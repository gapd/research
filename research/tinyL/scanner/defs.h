#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID	 1
#define INTEGER	 2
#define FLOAT	 3
#define PARAMETER 4
#define SEMICOLON 5
#define LPAR 6
#define RPAR 7
#define EQUAL 8
#define PERCENTAGE 9
#define SHARP 10
#define DOUBLEQUOTATION 11
#define PERIOD 12
#define LBRACE 13
#define RBRACE 14
#define UNDERBAR 15
#define COLON 16
#define BACKSLASH 17
#define AND 18
#define COMMENT 19	 
#define UNKNOWN 99

extern char *yytext;

int main(void);
int yylex(void);
