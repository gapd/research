%{
int linecounter = 1;
%}
%option nounput
%%
[a-zA-Z_][a-zA-Z0-9_]*		{ return(ID); }
[0-9]+				{ return(INTEGER); }
[0-9]*"."[0-9]+			{ return(REAL); }
";"				{ return(SEMICOLON); }
"="				{ return(EQUAL); }
"+"				{ return(ADD); }
"-"				{ return(SUBTRACT); }
"*"				{ return(MULTIPLY); }
"/"				{ return(DIVIDE); }
"("				{ return(LPAR); }
")"				{ return(RPAR); }
"\n"				{ linecounter++; }
"\r\n"				{ linecounter++; }
"\r"				{ linecounter++; }
" "|"\t"			{ }
"/*"				{ comment(); }
.				{ return(UNKNOWN); }
%%
int yywrap(void) {
	return(1);
}
void comment(void) {
	int boolean, first, second;

	boolean = TRUE;
	first = input();
	while (first != EOF && boolean) {
		second = input();
		if (first == '*' && second == '/') {
			boolean = FALSE;
		} else {
			first = second;
		}
	}
	if (first == EOF) {
		fprintf(stderr, "eof in comment\n");
	}
}

