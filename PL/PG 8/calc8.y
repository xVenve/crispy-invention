%{                      // SECCION 1 
#include <stdio.h>

char temp [2048] ;

#define FF fflush(stdout);

char *mi_malloc (int nbytes)
{
    char *p ;
    static long int nb = 0;
    static int nv = 0 ;
    
    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
        fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;
    
    return p ;
}


char *genera_cadena (char *nombre)
{
    char *p ;
    int l ;
    
    l = strlen (nombre)+1 ;
    p = (char *) mi_malloc (l) ;
    strcpy (p, nombre) ;
    
    return p ;
}


char *to_string(int n)
{
    sprintf(temp, "%d", n);
    
    return genera_cadena(temp);

}


%}
%union {                // El tipo de la pila (del AP) tiene caracter dual 
      int valor ;       //  - valor numerico entero 
      int indice ;      //  - indice para identificar una variable
      char *cadena ;
}                       // SECCION 2 

%token  <valor>  NUMERO    // Todos los token tienen un tipo para la pila
%token  <indice> VARIABLE

%type   <cadena>  expresion termino operando

%right  '='             //  es la ultima operacion que se debe realizar
%left   '+' '-'         //  menor orden de precedencia 
%left   '*' '/'         //  orden de precedencia intermedio 
%left   SIGNO_UNARIO    //  mayor orden de precedencia 
%%
                        // SECCION 3: Gramatica - Semantico


axioma:         expresion '\n'				{ ; }
                r_expr					{ ; }
            |   VARIABLE '=' expresion '\n'		{ ; }
                r_expr					{ ; }
            ;


r_expr:         /* lambda */				{ ; }
            |   axioma					{ ; }
            ;

expresion:      termino					{ ; }
            |   expresion '+' expresion   		{ ; }
            |   expresion '-' expresion   		{ ; }
            |   expresion '*' expresion   		{ ; }
            |   expresion '/' expresion   		{ ; }
            ;

termino:        operando				{ ; }                          
            |   '+' operando %prec SIGNO_UNARIO		{ ; }
            |   '-' operando %prec SIGNO_UNARIO		{ ; }    
                                                    
                                                 
            ;

operando:       VARIABLE				{ ; }
            |   NUMERO					{ ; }
            |   '(' expresion ')'			{ ; }
            ;

%%

                        /* SECCION 4  Codigo en C */
int n_linea = 1 ;

int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_linea) ;
}



int yylex ()
{
    unsigned char c ;

    do {
         c = getchar () ;
    } while (c == ' ') ;

    if (c == '.' || (c >= '0' && c <= '9')) {
         ungetc (c, stdin) ;
         scanf ("%d", &yylval.valor) ;
         return NUMERO ;
    }

    if (c >= 'A' && c <= 'Z') {
         yylval.indice = c - 'A' ;  // resta a c el valor ascii de A
         return VARIABLE ;
    }

    if (c >= 'a' && c <= 'z') {
         yylval.indice = c - 'a' ;  // resta a c el valor ascii de a 
         return VARIABLE ;
    }

    if (c == '\n')
          n_linea++ ;
    return c ;
}


int main ()
{
    yyparse () ;
}
