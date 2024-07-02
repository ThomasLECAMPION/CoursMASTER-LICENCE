grammar Calculette;

@parser::members {

    private int evalexpr (int x, String op, int y) {
        if ( op.equals("*") ){
            return x*y;
        } else if ( op.equals("+") ){
            return x+y;
        } else if ( op.equals("/") ) {
			return x/y;
		}
		else if ( op.equals("-") ) {
			return x-y;
		}
		else {
           System.err.println("Opérateur arithmétique incorrect : '"+op+"'");
           throw new IllegalArgumentException("Opérateur arithmétique incorrect : '"+op+"'");
        }
    }

}

start
    : resultat=expr EOF {System.out.println("Resultat = " + $resultat.val);};

expr returns [ int val ]
    : '(' a=expr ')' {$val = $a.val;}
	| a=expr op=('*'|'/') b=expr {$val = evalexpr($a.val, $op.text, $b.val);}
	| a=expr op=('+'|'-') b=expr {$val = evalexpr($a.val, $op.text, $b.val);}
	| entier=ENTIER {$val = $entier.int;}
	| '-' entier=ENTIER {$val = $entier.int * -1;}
    ;

// lexer
NEWLINE : '\r'? '\n'  -> skip;

WS :   (' '|'\t')+ -> skip  ;

ENTIER : ('0'..'9')+  ;

UNMATCH : . -> skip ;