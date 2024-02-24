%{
#include <stdio.h>
#include <stdlib.h>
#include "dag.cpp"
using namespace std;

void yyerror(char *s){
	printf("%s\n",s);
}

int yylex(void);
extern FILE *yyin;
extern DAG_Node* dag_array[1000];
%}

%union{
    int index;
    char addr[100];
}

%token NEWLINE PLUS MINUS SLASH ASTERISK LPAREN RPAREN
%token <addr> NUMBER
%token <addr> ID;
%type <index> expr
%type <index> term 
%type <index> factor


%%
line: expr NEWLINE           { print_dag_array(); construct_tac();}
    ;
expr: expr PLUS term         { $$ = constructNode("+",$1,$3); }
    | expr MINUS term        { $$ = constructNode("-",$1,$3); }
    | term
    ;
term: term ASTERISK factor   { $$ = constructNode("*",$1,$3); }
    | term SLASH factor      { $$ = constructNode("/",$1,$3); }
    | factor
    ;
factor:  LPAREN expr RPAREN  { $$ = $2; }
      | NUMBER {  $$ = constructNode(string($1),0,0); }
      | ID {  $$ = constructNode(string($1),0,0); }
      ;
%%

int main(int argc, char *argv[])
{
    // input file contains a single line with expression
    // write the output of your program in a text file named output.txt
    if(argc == 1) { 
        printf("Please provide input file\n");
        return 0;
    }

    // Redirect standard output to 'output.txt'
    freopen("output.txt", "w", stdout);

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        printf("Error opening input file.\n");
        return 1; // Return an error code
    }

    yyparse();

    // Close the input file
    fclose(yyin);

    // Optionally, restore stdout to its original state if needed
    // fclose(stdout);

    return 0;
}
