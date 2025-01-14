/* Jorge Rodríguez Fraile Carlos Rubio Olivares Grupo 3*/
/* 100405951@alumnos.uc3m.es 100405834@alumnos.uc3m.es */
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define T_NUMBER 1001
#define T_OP 1002

int ParseExpression(); // Prototype for forward reference

int token;  // Here we store the current token/literal
int number; // and the value of the number

int line_counter = 1;

int rd_lex() {
  int c;

  do {
    c = getchar();
  } while (c == ' ' || c == '\t');

  if (isdigit(c)) {
    ungetc(c, stdin);
    scanf("%d", &number);
    token = T_NUMBER;
    return (token); // returns the Token for Number
  }

  if (c == '\n')
    line_counter++; // info for rd_syntax_error ()

  token = c;
  return (token); // returns a literal
}

void rd_syntax_error(int expected, int token, char *output) {
  fprintf(stderr, "ERROR in line %d ", line_counter);
  fprintf(stderr, output, token, expected);

  exit(0);
}

void MatchSymbol(int expected_token) {
  if (token != expected_token) {
    rd_syntax_error(expected_token, token, "token %d expected, but %d was read");
  }
  rd_lex();
}

#define ParseLParen() MatchSymbol('('); // More concise and efficient definitions
#define ParseRParen() MatchSymbol(')'); // rather than using functions
#define ParseMinus() MatchSymbol('-');
#define ParsePlus() MatchSymbol('+');

// This is only useful for matching Literals

int ParseNumber() // Parsing Non Terminals and some Tokens require more
{                 // complex functions
  MatchSymbol(T_NUMBER);
  return number;
}

int ParseTerm() // T ::= N | ( E )      returns the numeric value of the Term
{
  int val;

  if (token == T_NUMBER) { // T derives alternatives, requires checking FIRST ( E )
    val = ParseNumber();
  } else if (token == '-') {
    ParseMinus();
    val = ParseTerm() * -1;
  } else if (token == '+') {
    ParsePlus();
    val = ParseTerm();
  } else {
    ParseLParen();
    val = ParseExpression();
    ParseRParen();
  }

  return val;
}

int ParseC() {
  int val;
  int val2;
  int operator;

  val = ParseTerm();

  if (token == '\n' || token == ')' || token == '+' || token == '-' || token == '*' || token == '/') {
    return val;
  }

  if (token == '^') {
    operator= token;
  } else {
    rd_syntax_error(token, 0, "Token %d was read, but an Operator was expected");
  }
  rd_lex();

  val2 = ParseC();

  if (operator== '^') {
    val = pow(val, val2);
  } else {
    rd_syntax_error(operator, 0, "Unexpected error in ParseExpressionRest for operator %c\n");
  }

  return val;
}

int ParseA() {
  int val;
  int val2;
  int operator;

  val = ParseC();

  if (token == '\n' || token == ')' || token == '+' || token == '-') {
    return val;
  }

  switch (token) {
  case '*':
  case '/':
    operator= token;
    break;
  default:
    rd_syntax_error(token, 0, "Token %d was read, but an Operator was expected");
    break;
  }
  rd_lex();

  val2 = ParseA();

  switch (operator) {
  case '*':
    val *= val2;
    break;
  case '/':
    val /= val2;
    break;
  default:
    rd_syntax_error(operator, 0, "Unexpected error in ParseExpressionRest for operator %c\n");
    break;
  }

  return val;
}

int ParseExpression() // E ::= TE' + E' ::= lambda | E
{                     // returns the numeric value of the Expression
  int val;
  int val2;
  int operator;

  val = ParseA();

  if (token == '\n' || token == ')') {
    return val;
  }

  switch (token) {
  case '+':
  case '-':
    operator= token;
    break;
  default:
    rd_syntax_error(token, 0, "Token %d was read, but an Operator was expected");
    break;
  }
  rd_lex();

  val2 = ParseExpression();

  switch (operator) {
  case '+':
    val += val2;
    break;
  case '-':
    val -= val2;
    break;
  default:
    rd_syntax_error(operator, 0, "Unexpected error in ParseExpressionRest for operator %c\n");
    break;
  }

  return val;
}

int main(void) {

  while (1) {
    rd_lex();
    printf("Valor %d\n", ParseExpression());
  }

  system("PAUSE");
}
