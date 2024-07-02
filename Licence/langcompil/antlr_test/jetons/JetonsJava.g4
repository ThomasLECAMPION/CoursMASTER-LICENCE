lexer grammar JetonsJava;

OPERATEUR
    : ('<'|'<='|'>'|'>='|'=='|'!=')
	  { System.out.print(getText()); } 
    ;

MOTCLE
    : ( 'break' | 'class' | 'double' | 'else' | 'if' | 'import' | 'public' | 'static' | 'throws' ) 
      { System.out.print("[motclé : "+getText()+" ]"); } 
    ;
    
IDENTIFIANT 
    :   ('a'..'z' | 'A'..'Z' | '_')('a'..'z' | 'A'..'Z' | '_' | '0'..'9')*
		{ System.out.print("[ident : "+getText()+" ]"); }
    ;

WHITE_SPACE
    : (' '|'\n'|'\t'|'\r')+ 
      { System.out.print(getText()); } 
    ;

UNMATCH 
    : . 
      { System.out.print(getText()); } 
    ;
