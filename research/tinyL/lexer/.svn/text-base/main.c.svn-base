#include "defs.h"

int main(void) {
	int  tokenNumber;
	char *tokenString;

	while((tokenNumber = yylex()) != 0) {
		tokenString = strdup(yytext);
		printf("token number = %d,\t", tokenNumber);
		printf("token string = %s\n", tokenString);
	}
	return(EXIT_SUCCESS);
}
