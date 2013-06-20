%{
int linecounter = 1;
%}
%option nounput
%%
"stroke"					{ return(STROKE); }
"fill"				{ return(FILL); }
"rectangle"				{ return(RECTANGLE); }
"display"			{ fprintf(stderr, "%s\n", yytext); return(DISPLAY); }
"line"					{ return(LINE); }
"arc"				{ return(ARC); }
"string"			{ return(STRING); }
"image"			{ fprintf(stderr, "%s\n", yytext); return(IMAGE); }
"start"			{ return(START); }
"end"			{ return(END); }
"pass"			{ return(PASS); }
"angle"			{ return(ANGLE); }
"sweep"			{ return(SWEEP); }
"at"			{ return(AT); }
"color"			{ return(COLOR); }
"width"			{ return(WIDTH); }
[0-9]+					{ return(INTEGER); }
"@"			{ return(ATMARK); }
[\"].*[\"]			{ return(WQUOTED); }
"red"			{ return(RED); }
"green"			{ return(GREEN); }
"blue"			{ return(BLUE); }
"cyan"			{ return(CYAN); }
"magenta"			{ return(MAGENTA); }
"yellow"			{ return(YELLOW); }
"gray"			{ return(GRAY); }
"black"			{ return(BLACK); }
"white"			{ return(WHITE); }
"."			{ fprintf(stderr, "%s\n", yytext); return(PERIOD); }
"\n"					{ linecounter++; }
"\r\n"					{ linecounter++; }
"\r"					{ linecounter++; }
" "|"\t"				{ }
"/*"					{ comment(); }
.					{ return(UNKNOWN); }
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
		} else if (first == '\r' && second == '\n') {
			linecounter++;
			first = input();
		} else {
			if (first == '\r' || first == '\n') {
				linecounter++;
			}
			first = second;
		}
	}
	if (first == EOF) {
		fprintf(stderr, "eof in comment\n");
	}
}
