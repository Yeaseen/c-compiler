%option noyywrap

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include "y.tab.h"

using namespace std;

extern YYSTYPE yylval;

void yyerror(char *);
%}


WS [ \t]+
DIGIT [0-9]
LETTER [A-Za-z]
NUMBER {DIGIT}+
ID (_|{LETTER})(_|{LETTER}|{DIGIT})*

%%

{NUMBER}  {
  		strcpy(yylval.addr,yytext);
	    return NUMBER;
    }

{ID} {
		strcpy(yylval.addr,yytext);
		return ID;
    }

"+"       { return PLUS; }
"-"       { return MINUS; }
"/"       { return SLASH; }
"*"       { return ASTERISK; }
"("       { return LPAREN; }


")"       { return RPAREN; }
"\n"      { return NEWLINE; }
{WS} { /* No action and no return */}

%%
