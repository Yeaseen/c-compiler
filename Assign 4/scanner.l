
%{
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include"y.tab.h"
#include"SymbolTable.h"
using namespace std;




extern YYSTYPE yylval;
//SymbolTable* table=new SymbolTable(7);
extern SymbolTable* table;
void yyerror(char *);

extern FILE* errorout;
int lin_count=1;
int error_count=0;;
int c;




%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [_a-zA-Z]
DIGIT [0-9]
FLOAT_NUMBER [0-9]*([.][0-9]+)?(E[+-]?[0-9]+)?
IDENTIFIER ([a-zA-Z0-9_]([a-zA-Z0-9_]*)?)
NEWLINE \n
NOT_IDENTIFIER [0-9]+(\.)?[A-Za-z0-9_]+
DECIMAL_POINT_ERROR [0-9]*[.][0-9]*([.]+[0-9]*)*

ILL_FORMATTED_NUMBER  [0-9]*((E[+-]?[0-9]+)([.][0-9]+)*)(E[+-]?[0-9]+)?([.][0-9]+)*


%%

{WHITESPACE}       {}

{NEWLINE} {lin_count++;}

"if"	{   return IF;}
"else"	{   return ELSE;}
"for"	{   return FOR;}
"while" {   return WHILE;}
"int"	{   return INT;}
"float"	{   return FLOAT;}
"void"	{   return VOID;}
"char"	{   return CHAR;}
"println"	{return PRINTLN;}

"return"	{return RETURN;}

[+-]		{
                     SymbolInfo *s= new  SymbolInfo(yytext,"ADDOP");
			yylval = (YYSTYPE)s;
			return ADDOP;
			}
[*/%]		{
			
			SymbolInfo *s= new  SymbolInfo(yytext,"MULOP");
			yylval = (YYSTYPE)s;
			return MULOP;
	}


">"|">="|"<"|"<="|"=="|"!="		{

			SymbolInfo *s= new  SymbolInfo(yytext,"RELOP");
		yylval = (YYSTYPE)s;
		return RELOP;

                                     }
"="		{
			return ASSIGNOP;
			}

"&&"|"||"		{
			SymbolInfo *s= new  SymbolInfo(yytext,"LOGICOP");
			yylval = (YYSTYPE)s;
			return LOGICOP;
		        }
"!"                     {  return NOT;			}
"("		{SymbolInfo *s= new SymbolInfo(yytext, "LCURL");
				
				yylval = (YYSTYPE)s;  return LPAREN;}
")"		{return RPAREN;}
"{"		{  		SymbolInfo *s= new SymbolInfo(yytext, "LCURL");
				
				yylval = (YYSTYPE)s;   return LCURL;}
"}"		{return RCURL;}
"["		{return LTHIRD;}
"]"		{return RTHIRD;}
","		{return COMMA;}
";"		{return SEMICOLON;}
"++"		{return INCOP;}
"--"		{return DECOP;}






		
{DIGIT}+ 	{      
				

                            SymbolInfo *s= new  SymbolInfo(yytext, "CONST_INT");
                                s->value.ival=atoi(yytext);
                                s->value.c=0;
				yylval = (YYSTYPE)s;
				return CONST_INT;
	  	}

{FLOAT_NUMBER} {
				SymbolInfo *s= new  SymbolInfo(yytext, "CONST_FLOAT");
                                s->value.fval=atof(yytext);
                                s->value.c=1;
				yylval = (YYSTYPE)s;
				return CONST_FLOAT; 
               }

{NOT_IDENTIFIER}  {
			fprintf(errorout,"Error at line no %d: Invalid prefix on ID or invalid suffix on Number\n\n",lin_count);
			error_count++;
                       
                        
		}




{IDENTIFIER}  {

                       		SymbolInfo *s= new SymbolInfo(yytext, "ID");
				s->value.c=-1;
				yylval = (YYSTYPE)s;
							
				return ID;
              }



{DECIMAL_POINT_ERROR} {	fprintf(errorout,"Error at line no %d: Too many decimal point\n\n",lin_count);
			error_count++;


                                     }		   

{ILL_FORMATTED_NUMBER} {fprintf(errorout,"Error at line no %d: Ill formed number \n\n",lin_count);
			error_count++;

			}







			

%%

int yywrap(void)
{
	return 1;
}

