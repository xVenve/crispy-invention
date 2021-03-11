/* Jorge Rodríguez Fraile Carlos Rubio Olivares Grupo 3*/
/* 100405951@alumnos.uc3m.es 100405834@alumnos.uc3m.es */
%{                      /* SECCION 1 */
#include <stdio.h>
double memoria [52] ;   /* Se define una zona de memoria para las variables */
%}
%union {                /* El tipo de la pila (del AP) tiene caracter dual */
      double valor ;    /*  - valor numerico real */
      int indice ;      /*  - indice para identificar una variable */
}                       /* SECCION 2 */
%token  <valor>  NUMERO    /* Todos los token tienen un tipo para la pila   */
%token  <indice> VARIABLE
%type   <valor>  expresion /* Se asocia tambien a los No Terminales un tipo */
%type   <valor>  termino operando
%right  '='             /*  es la ultima operacion que se debe realizar */
%left   '+' '-'         /*  menor orden de precedencia */
%left   '*' '/'         /*  orden de precedencia intermedio */
%left   SIGNO_UNARIO    /*  mayor orden de precedencia  */
%%

                        /* SECCION 3: Gramatica - Semantico  */

axioma:       expresion '\n'              { printf ("Expresion=%lf\n", $1) ; }
                       r_expr
            | VARIABLE '=' expresion '\n' { memoria [$1] = $3;
                                            printf ("%c=%lf\n", $1+'A', $3);
                                          }
                       r_expr
            ;

r_expr:                      /* lambda */
            | axioma
            ;

expresion:    termino                    { $$ = $1; }
            | expresion '+' expresion    { $$ = $1 + $3;  }
            | expresion '-' expresion    { $$ = $1 - $3;  }
            | expresion '*' expresion    { $$ = $1 * $3;  }
            | expresion '/' expresion    { $$ = $1 / $3;  }
            ;

termino:      operando                           { $$ = $1; }
            | '+' operando %prec SIGNO_UNARIO    { $$ = $2; }
            | '-' operando %prec SIGNO_UNARIO    { $$ = -$2; }
            ;

operando:     VARIABLE                   { $$ = memoria [$1]; }
            | NUMERO                     { $$ = $1; }
            | '(' expresion ')'          { $$ = $2; }
            ;
%%


                        /* SECCION 4  Codigo en C */
int n_linea = 1 ;

int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_linea) ;
}

/*
int yylex ()
{
    unsigned char c ;

    do {
         c = getchar () ;
    } while (c == ' ') ;

    if (c == '.' || (c >= '0' && c <= '9')) {
         ungetc (c, stdin) ;
         scanf ("%lf", &yylval.valor) ;
         return NUMERO ;
    }

    if (c >= 'A' && c <= 'Z') {
         yylval.indice = c - 'A' ;  /* resta a c el valor ascii de A
         return VARIABLE ;
    }

    if (c >= 'a' && c <= 'z') {
         yylval.indice = 32 + c - 'a'  ;  /* resta a c el valor ascii de a
         return VARIABLE ;
    }

    if (c == '\n')
          n_linea++ ;
    return c;
}
*/

int main ()
{
    yyparse () ;
}
