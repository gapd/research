%{
#include "defs.h"
%}
%option nounput
%%
[i][n][t]				{ return(INT); }
[f][l][o][a][t]				{ return(FLOAT); }
[p][r][i][n][t]		       		{ return(PRINT); }
[a-zA-Z][a-zA-Z0-9]*		       	{ return(ID); }
[0-9]+			                { return(INTEGER); }
[0-9]+"."[0-9]* 		      	{ return(REAL); }
";"					{ return(SEMICOLON); }
","					{ return(COMMA); }
"="					{ return(EQUAL); }
"+"					{ return(ADD); }
"-"					{ return(SUBTRACT); }
"*"					{ return(MULTIPLY); }
"/"					{ return(DIVIDE); }
"("					{ return(LPAR); }
")"					{ return(RPAR); }
"\r"|"\n"|" "|"\t"			{ }
"/*".*"*/"				{ }
.					{ return(UNKNOWN); }
%%
int yywrap(void) {
	return(1);
}
