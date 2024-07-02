grammar Calculette;

@members {
   private TableSymboles tableSymboles = new TableSymboles();
   private int _cur_label = 1;
    /** générateur de nom d'étiquettes pour les boucles */
    private String getNewLabel() { return "b" +(_cur_label++); }
}

start
    : calcul EOF
	;

calcul returns [ String code ]
@init{ $code = new String(); }   // On initialise code, pour ensuite l'utiliser comme accumulateur
@after{System.out.print($code);}
    : 	(decl { $code += $decl.code; })*
	
        NEWLINE*

        (instruction { $code += $instruction.code; })*

        { $code += "HALT\n"; }
    ;

instruction returns [ String code ] 
@init{ $code = new String();} 
    : expression finInstruction 
        { 
            $code = $expression.code;
        }
    | assignation finInstruction
        { 
			$code = $assignation.code;
        }
	| 'read' '(' IDENTIFIANT ')' finInstruction
		{
			$code = "READ\n" + "STOREG " + tableSymboles.getAdresseType($IDENTIFIANT.text).adresse + "\n";
		}
	| 'write' '(' expression ')' finInstruction
		{
			$code = $expression.code + "WRITE\n" + "POP\n";
		}
	| 'while' '(' condition ')' {String i="";}(instruction{i+=$instruction.code;}|bloc{i+=$bloc.code;})
		{
			String debut = getNewLabel();
			String fin = getNewLabel();
			$code = "LABEL " + debut + "\n" + $condition.code + "JUMPF " + fin + "\n";
			$code += i;
			$code += "JUMP " + debut + "\n" + "LABEL " + fin + "\n";
		}
	| 'if' '(' condition ')' {String bthen="";String belse="";}(instruction{bthen+=$instruction.code;}|bloc{bthen+=$bloc.code;}) ('else' (instruction{belse+=$instruction.code;}|bloc{belse+=$bloc.code;}) {$code="ok";})?
		{
			String fin = getNewLabel();			
			if($code.equals("")){
				$code = $condition.code + "JUMPF " + fin + "\n" + bthen + "LABEL " + fin + "\n";					
			}
			else {
				String sinon = getNewLabel();
				$code = $condition.code + "JUMPF " + sinon + "\n" + bthen + "JUMP " + fin + "\nLABEL " + sinon + "\n" + belse + "LABEL " + fin + "\n";
			}
		}
	| 'for' '(' init=assignation? ';' c=condition? ';' incr=assignation? ')' {String i="";}(instruction{i+=$instruction.code;}|bloc{i+=$bloc.code;})
		{
			String debut = getNewLabel();
			String fin = getNewLabel();
			$code = $init.code + "LABEL " + debut + "\n";
			$code += $c.code + "JUMPF " + fin + "\n";
			$code += i + $incr.code + "JUMP " + debut + "\n" + "LABEL " + fin + "\n";
		}
	| 'repeat' {String i="";}(instruction{i+=$instruction.code;}|bloc{i+=$bloc.code;}) 'until' '(' c=condition? ')' finInstruction
		{
			String debut = getNewLabel();
			$code = "LABEL " + debut + "\n" + i + $c.code + "JUMPF " + debut + "\n";
		}
	| finInstruction
        {
            $code = "";
        }
    ;

fonction returns [ String code ]
    : TYPE IDENTIFIANT '('  params ? ')' 
        { 
            // truc à faire par rapport au "type" de la fonction
        }
        bloc 
        {
            $code += $bloc.code;
        }
    ;

params
    : TYPE IDENTIFIANT 
        { 
            // code java gérant la déclaration de "la variable" de retour de la fonction
        }  
        ( ',' TYPE IDENTIFIANT 
            { 
                // code java gérant une variable locale (argi)
            } 
        )*
    ;

args returns [ String code, int size] @init{ $code = new String(); $size = 0; }
    : ( expression
    { 
        // code java pour première expression pour arg
    }
    ( ',' expression
    { 
        // code java pour expression suivante pour arg
    } 
    )* 
      )? 
    ;

expression returns [ String code ]
    : '(' expression ')' {$code = $expression.code;}
	| a=expression op=('*'|'/') b=expression {
		switch($op.text){
			case "*":
				$code = $a.code + $b.code + "MUL\n";
				break;
			case "/":
				$code = $a.code + $b.code + "DIV\n";
				break;
		}
	}
	| a=expression op=('+'|'-') b=expression {
		switch($op.text){
			case "+":
				$code = $a.code + $b.code + "ADD\n";
				break;
			case "-":
				$code = $a.code + $b.code + "SUB\n";
				break;
		}
	}
	| IDENTIFIANT '(' args ')' 
        {  
			$code = "CALL " ;
        }
	| ENTIER {$code = "PUSHI " + $ENTIER.int + "\n";}
	| '-' ENTIER {$code = "PUSHI " + $ENTIER.int*(-1 ) + "\n";}
	| IDENTIFIANT {$code = "PUSHG " + tableSymboles.getAdresseType($IDENTIFIANT.text).adresse + "\n";}
    ;

finInstruction : ( NEWLINE | ';' )+ ;

decl returns [ String code ] 
    :
        TYPE IDENTIFIANT finInstruction
        {
            $code = "PUSHI 0\n";
			tableSymboles.putVar($IDENTIFIANT.text,$TYPE.text);
        }
		| TYPE IDENTIFIANT '=' expression finInstruction
        {
            $code = $expression.code;
			tableSymboles.putVar($IDENTIFIANT.text,$TYPE.text);
        }
    ; 

assignation returns [ String code ] 
    : IDENTIFIANT '=' expression
        {  
            $code = $expression.code + "STOREG " + tableSymboles.getAdresseType($IDENTIFIANT.text).adresse + "\n";
        }
	| IDENTIFIANT '++'
		{
			$code = "PUSHI 1\nSTOREG " + tableSymboles.getAdresseType($IDENTIFIANT.text).adresse + "\n";
		}
    ;
	
condition returns [ String code ]
    : 'true'  { $code = "PUSHI 1\n"; }
    | 'false' { $code = "PUSHI 0\n"; }
	| a=expression '==' b=expression { $code = $a.code + $b.code + "EQUAL\n"; }
	| a=expression ('!='|'<>') b=expression { $code = $a.code + $b.code + "NEQ\n"; }
	| a=expression '<=' b=expression { $code = $a.code + $b.code + "INFEQ\n"; }
	| a=expression '>=' b=expression { $code = $a.code + $b.code + "SUPEQ\n"; }
	| a=expression '<' b=expression { $code = $a.code + $b.code + "INF\n"; }
	| a=expression '>' b=expression { $code = $a.code + $b.code + "SUP\n"; }
	| c1=condition '&&' c2=condition { $code = $c1.code + $c2.code + "MUL\n"; }
	| c1=condition '||' c2=condition { $code = $c1.code + $c2.code + "ADD\nPUSHI 1\nSUPEQ\n"; }
	| '!' condition {$code = $condition.code + "PUSHI -1\nMUL\nPUSHI 1\nADD\n";}
    ;

bloc returns [ String code ]
@init{ $code = new String(); }
	: '{' (instruction {$code += $instruction.code;})+ '}' finInstruction
	;

// lexer
TYPE : 'int' | 'float' ;

NEWLINE : '\r'? '\n'  ;

WS :   (' '|'\t')+ -> skip  ;

ENTIER : ('0'..'9')+  ;
 
MULTICOMMENTAIRE : '/*' .*? '*/' -> skip ;

SINGLECOMMENTAIRE : '//' ~('\r' | '\n')* -> skip ;

IDENTIFIANT : ('a'..'z')('a'..'z' | 'A'..'Z' | '_' | '0'..'9')* ;

UNMATCH : . -> skip ;