%{
#include "defs.h"
%}
%option nounput
%%
[a-zA-Z][a-zA-Z0-9]*		{ return(ID); }
"("[a-z]*" "[a-z]*","" "[a-z]*" ""*"*[a-z]*")"     { return(PARAMETER); }
"/*".*"*/"                 { return(COMMENT); }
[0-9]+"."[0-9]*                 { return(FLOAT); }
[0-9]+				{ return(INTEGER); }
"("				{ return(LPAR); }
"="				{ return(EQUAL); }
";"				{ return(SEMICOLON); }
"%"				{ return(PERCENTAGE); }
"#"				{ return(SHARP); }
"\""				{ return(DOUBLEQUOTATION); }
"."				{ return(PERIOD); }
"{"				{ return(LBRACE); }
"}"				{ return(RBRACE); }
")"				{ return(RPAR); }
"_"				{ return(UNDERBAR); }
","				{ return(COLON); }
"\\"				{ return(BACKSLASH); }
"&"				{ return(AND); }
"\r"|"\n"|" "|"\t"		{ }
.				{ return(UNKNOWN); }
%%
int yywrap(void) {
	return(1);
}
