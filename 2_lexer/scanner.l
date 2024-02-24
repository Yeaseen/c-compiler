%option noyywrap
%x COMMENT
%x ASTRING 
%x MYSTATE
%{
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
using namespace std;

int line_count=1;
int error_count=0;
int c;
string temp="";
string temp1="";
string temp2="";
string temp3="";

FILE *logout;
FILE *tokenout;





class SymbolInfo
{
        private:
               string name;
               string type;
        public:
        SymbolInfo* next;

        void setName(string name)
        {
            this->name=name;
        }
        string getName()
        {
            return this->name;
        }
        void setType(string type)
        {
            this->type=type;
        }
        string getType()
        {
            return this->type;
        }

        SymbolInfo(string name, string type)
        {
            setName(name);
            setType(type);
            this->next=NULL;
        }
        SymbolInfo()
        {
            this->name="";
            this->type="";
            this->next=NULL;
        }


};



class ScopeTable
{
     private:
         SymbolInfo** htable;



     public:
         int range;
         ScopeTable* parentScope;
         int scope_id;

         ScopeTable(int range, int id)
         {
             this->range=range;
             htable= new SymbolInfo*[range];
             for(int i=0;i<range;i++) htable[i]= new SymbolInfo() ;
             this->scope_id=id;
             this->parentScope=NULL;

         }
        ~ScopeTable()
        {
            for (int i = 0; i <range; i++)
	    {
                SymbolInfo* entry = htable[i];
                while (entry != NULL)
	        {
                    SymbolInfo* prev = entry;
                    entry = entry->next;
                    delete prev;
            }
        }
            delete[] htable;
        }


         int HashFunc(string name)
        {
            int p,q=0;
            for(int i=0;i<name.size();i++)
            {
                p=(int)name[i];
                q=(q+ p%range)%range;
            }

            return q;

        }
        
        void Insert(string name, string type)
        {
            int k=0;
            int t=HashFunc(name);


            SymbolInfo* entry= htable[t]->next;

            while(entry!=NULL)
            {
                if(entry->getName()==name)
                {
                    k=1;
                    fprintf(logout,"already exist\n");
                    break;
                }
                entry=entry->next;
            }

            if(k==0)
            {


            int hash_val=HashFunc(name);

            SymbolInfo* entry= htable[hash_val];

             int p=0;

            while(entry->next!=NULL)
            {


                entry=entry->next;
                p++;
            }

            if (entry->next == NULL)
            {
                entry->next = new SymbolInfo(name,type);
            }



            //cout<<"Inserted in Scopetable#" <<scope_id<<"  at Position  " <<hash_val<<", "<<p;

            }


        }




        void PA()
        {
            
            fprintf(logout,"Scopetable--> %d \n",scope_id);
            for(int i=0;i<range;i++)
            {


            SymbolInfo* entry= htable[i]->next;
            
            if(entry!=NULL)
            {
            fprintf(logout,"--> %d ",i);
            
            
            while(entry!=NULL)
            {
                char a[250];
		std::string s = "<" + entry->getName() + ":" + entry->getType() + "> ";
		strcpy(a,s.c_str());
		a[sizeof(a) - 1] = 0;
		fprintf(logout,"%s",a);
                entry=entry->next;
            }
             fprintf(logout,"\n");
            }
            }
            
          fprintf(logout,"\n");

        }
        


        


};

class SymbolTable
{
     public:
         ScopeTable* stable;
         int range;

         SymbolTable(int range)
         {
            this->range=range;
            stable=new ScopeTable(range,1);
         }




         void InsertS(string name,string type)
         {
             stable->Insert(name,type);
         }

         
         void PrintCurrent()
         {
             stable->PA();
         }
         



};



SymbolTable ob(7);


void cmain(string name, string type)
{
       
       ob.InsertS(name,type);
       ob.PrintCurrent();

}

%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [_a-zA-Z]
CHAR [ -~]{-}[']
CHARS {CHAR}+

CHARACTER '[a-z0-9A-Z]'
CHARACTEREXT '\\[ntabf\\v0r"v]                                                                                                                                                                                                      
MULTI_CHAR ('[A-Za-z0-9 ][ A-Za-z0-9]+')
EMPTYCHAR ('')
UNRE_CHAR ('{CHAR}*[\\]?[^'\n]?)|'[\\]'
DIGIT [0-9]
FLOAT_NUMBER [0-9]*([\.][0-9]+)?(E[+-]?[0-9]+)?
IDENTIFIER ([a-zA-Z0-9_]([a-zA-Z0-9_]*)?)
ANY [^\"\n]


STRINGNEWLINE \\\n
STRINGSPC \\[ntabfv0\\r"v]
NEWLINE \n

CMNT_START "//"
EXTEND "\\\n"
NOT_IDENTIFIER [0-9]+(\.)?[A-Za-z0-9_]+

DECIMAL_POINT_ERROR [0-9]*[.][0-9]*([.]+[0-9]*)*

ILL_FORMATTED_NUMBER  [0-9]*((E[+-]?[0-9]+)([.][0-9]+)*)(E[+-]?[0-9]+)?([.][0-9]+)*


%%

{WHITESPACE}       {}

{NEWLINE} {line_count++;}

"if"	{
			fprintf(tokenout,"<IF>");
			fprintf(logout,"Line no %d: TOKEN <IF> Lexeme %s found\n",line_count,yytext);
		}
"else"	{
			fprintf(tokenout,"<ELSE>");
			fprintf(logout,"Line no %d: TOKEN <ELSE> Lexeme %s found\n\n",line_count,yytext);
		}


"for"	{
			fprintf(tokenout,"<FOR>");
			fprintf(logout,"Line no %d: TOKEN <FOR> Lexeme %s found\n\n",line_count,yytext);
		}
"do"	{
			fprintf(tokenout,"<DO>");
			fprintf(logout,"Line no %d: TOKEN <DO> Lexeme %s found\n\n",line_count,yytext);
		}
"int"	{
			fprintf(tokenout,"<INT>");
			fprintf(logout,"Line no %d: TOKEN <INT> Lexeme %s found\n\n",line_count,yytext);
		}
"float"	{
			fprintf(tokenout,"<FLOAT>");
			fprintf(logout,"Line no %d: TOKEN <FLOAT> Lexeme %s found\n\n",line_count,yytext);

		}
"void"	{
			fprintf(tokenout,"<VOID>");
			fprintf(logout,"Line no %d: TOKEN <VOID> Lexeme %s found\n\n",line_count,yytext);
		}
"switch"	{
			fprintf(tokenout,"<SWITCH>");
			fprintf(logout,"Line no %d: TOKEN <SWITCH> Lexeme %s found\n\n",line_count,yytext);
		}
"default"	{
			fprintf(tokenout,"<DEFAULT>");
			fprintf(logout,"Line no %d: TOKEN <DEFAULT> Lexeme %s found\n\n",line_count,yytext);
		}

"while"	{
			fprintf(tokenout,"<WHILE>");
			fprintf(logout,"Line no %d: TOKEN <WHILE> Lexeme %s found\n\n",line_count,yytext);
		}
"break"	{
			fprintf(tokenout,"<BREAK>");
			fprintf(logout,"Line no %d: TOKEN <BREAK> Lexeme %s found\n\n",line_count,yytext);
		}
"char"	{
			fprintf(tokenout,"<CHAR>");
			fprintf(logout,"Line no %d: TOKEN <CHAR> Lexeme %s found\n\n",line_count,yytext);
		}
"double"	{
			fprintf(tokenout,"<DOUBLE>");
			fprintf(logout,"Line no %d: TOKEN <DOUBLE> Lexeme %s found\n\n",line_count,yytext);
		}
"return"	{
			fprintf(tokenout,"<RETURN>");
			fprintf(logout,"Line no %d: TOKEN <RETURN> Lexeme %s found\n\n",line_count,yytext);
		}
"case"	{
			fprintf(tokenout,"<CASE>");
			fprintf(logout,"Line no %d: TOKEN <CASE> Lexeme %s found\n\n",line_count,yytext);
		}
"continue"	{
			fprintf(tokenout,"<CONTINUE>");
			fprintf(logout,"Line no %d: TOKEN <CONTINUE> Lexeme %s found\n\n",line_count,yytext);
		}





[+-]		{
			fprintf(tokenout,"<ADDOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ADDOP> Lexeme %s found\n\n",line_count,yytext);
			}
[*/%]		{
			fprintf(tokenout,"<MULOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <MULOP> Lexeme %s found\n\n",line_count,yytext);
			}
"++"|"--"		{
			fprintf(tokenout,"<INCOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <INCOP> Lexeme %s found\n\n",line_count,yytext);
			}
">"|">="|"<"|"<="|"=="|"!="		{
			fprintf(tokenout,"<RELOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RELOP> Lexeme %s found\n\n",line_count,yytext);
			}
"="		{
			fprintf(tokenout,"<ASSIGNOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ASSIGNOP> Lexeme %s found\n\n",line_count,yytext);
			
			}
"&&"|"||"		{
			fprintf(tokenout,"<LOGICOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LOGICOP> Lexeme %s found\n\n",line_count,yytext);
			}
"!"                     {
			fprintf(tokenout,"<NOT,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <NOT> Lexeme %s found\n\n",line_count,yytext);
			}
"("		{
			fprintf(tokenout,"<LPAREN,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LPAREN> Lexeme %s found\n\n",line_count,yytext);
			}
")"		{
			fprintf(tokenout,"<RPAREN,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RPAREN> Lexeme %s found\n\n",line_count,yytext);
			}
"{"		{
			fprintf(tokenout,"<LCURL,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LCURL> Lexeme %s found\n\n",line_count,yytext);
			}
"}"		{
			fprintf(tokenout,"<RCURL,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RCURL> Lexeme %s found\n\n",line_count,yytext);
			}
"["		{
			fprintf(tokenout,"<LTHIRD,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LBRACKET> Lexeme %s found\n\n",line_count,yytext);
			
			}
"]"		{
			fprintf(tokenout,"<RTHIRD,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RBRACKET> Lexeme %s found\n\n",line_count,yytext);
			
			}
","		{
			fprintf(tokenout,"<COMMA,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <COMMA> Lexeme %s found\n\n",line_count,yytext);
			
			}
";"		{
			fprintf(tokenout,"<SEMICOLON,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <SEMICOLON> Lexeme %s found\n\n",line_count,yytext);
			
			}






		
{DIGIT}+ 	{
				fprintf(tokenout,"<CONST_INT,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <CONST_INT> Lexeme %s found\n",line_count,yytext);
                                cmain(yytext,"CONST_INT");
				//insert in symbol table and print symbol table content(only non empty buckets)
	  	}

{FLOAT_NUMBER} {
				fprintf(tokenout,"<CONST_FLOAT,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <CONST_FLOAT> Lexeme %s found\n",line_count,yytext);
				//insert in symbol table and print symbol table content(only non empty buckets)
	                        cmain(yytext,"CONST_FLOAT");
		}

{CHARACTER}    { 
                fprintf(tokenout,"<CONST_CHAR,%c>",yytext[1]);
		fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> %s found\n",line_count,yytext);
                cmain(yytext,"CONST_CHAR");   
               }    
   

{CHARACTEREXT}    {     if(yytext[2]=='t') fprintf(tokenout,"<CONST_CHAR,%c>",'\t');
                        if(yytext[2]=='n') fprintf(tokenout,"<CONST_CHAR,%c>",'\n');
                        if(yytext[2]=='a') fprintf(tokenout,"<CONST_CHAR,%c>",'\a');
                        if(yytext[2]=='f') fprintf(tokenout,"<CONST_CHAR,%c>",'\f');
                        if(yytext[2]=='r') fprintf(tokenout,"<CONST_CHAR,%c>",'\r');
                        if(yytext[2]=='b') fprintf(tokenout,"<CONST_CHAR,%c>",'\b');
                        if(yytext[2]=='v') fprintf(tokenout,"<CONST_CHAR,%c>",'\v');
                        if(yytext[2]=='0') fprintf(tokenout,"<CONST_CHAR,%c>",'\0');
                        if(yytext[2]=='"') fprintf(tokenout,"<CONST_CHAR,%c>",'\"');
                        
                        if(yytext[2]=='\\') fprintf(tokenout,"<CONST_CHAR,%c>",'\\');                        
			fprintf(logout,"Line no %d:<CONST_CHAR> %s found\n",line_count,yytext);
                        cmain(yytext,"CONST_CHAR");

             }
{EMPTYCHAR}    {        fprintf(logout,"Error at line no %d: Empty character constant error %s\n\n",line_count,yytext);
			error_count++;
                  }


{MULTI_CHAR}    {        fprintf(logout,"Error at line no %d: MUulti character constant error %s\n\n",line_count,yytext);
			error_count++;
                  }

{UNRE_CHAR}                         {
			fprintf(logout,"Error at line no %d: Unterminated character %s\n\n",line_count,yytext);
			error_count++;
			}


{NOT_IDENTIFIER}  {
			fprintf(logout,"Error at line no %d: Invalid prefix on ID or invalid suffix on Number %s\n\n",line_count,yytext);
			error_count++;
		}


{IDENTIFIER}  {
		  fprintf(tokenout,"<ID,%s>",yytext);
       		  fprintf(logout,"Line no %d: TOKEN <ID> Lexeme %s found\n\n",line_count,yytext);
		  cmain(yytext,"ID");
	      }




{DECIMAL_POINT_ERROR} {	fprintf(logout,"Error at line no %d: Too many decimal point %s\n\n",line_count,yytext);
			error_count++;


                                     }		   

{ILL_FORMATTED_NUMBER} {fprintf(logout,"Error at line no %d: Ill formed number %s\n\n",line_count,yytext);
			error_count++;

			}



\"           {  BEGIN (ASTRING);
                 temp2=temp2+yytext;
                 
                 //fprintf(tokenout,"<STRING,");
                  c=line_count; 
                //fprintf(logout,"Line no %d: TOKEN <STRING> Lexeme %s",line_count,yytext);

             }

<ASTRING>{ANY} {   temp3=temp3+yytext;
                   temp2=temp2+yytext;
                   
                }
<ASTRING>{STRINGNEWLINE} {line_count++;
                     //temp3=temp3+yytext;
                     temp2=temp2+yytext;
                     }

<ASTRING>{STRINGSPC} {
                       if(yytext[1]=='n') temp3=temp3+'\n';   
                       if(yytext[1]=='t') temp3=temp3+'\t';
                       if(yytext[1]=='a') temp3=temp3+'\a';
                       if(yytext[1]=='f') temp3=temp3+'\f';
                       if(yytext[1]=='r') temp3=temp3+'\r';
                       if(yytext[1]=='b') temp3=temp3+'\b';
                       if(yytext[1]=='v') temp3=temp3+'\v';
                       if(yytext[1]=='0') temp3=temp3+'\0';
                       if(yytext[1]=='"') temp3=temp3+'\"';
                       if(yytext[1]=='\\') temp3=temp3+'\\'; 
                       
                       temp2=temp2+yytext;
                       
                     }

<ASTRING>{NEWLINE}  {
                      fprintf(logout,"Error at line no %d: Unterminated String %s\n\n",c,temp2.c_str());
                      error_count++;
                      line_count++;
                      BEGIN INITIAL;
                      temp2="";
                      //temp3="";  
                         
                    }
<ASTRING>\" { 
              temp2=temp2+yytext;
              //temp3=temp3+yytext;
              fprintf(tokenout,"<STRING,%s>",temp3.c_str());
              fprintf(logout,"Line no %d: TOKEN <STRING> Lexeme %s found\n\n",c,temp2.c_str());
              BEGIN INITIAL;
              temp2="";
              temp3="";
              
              
             }





{CMNT_START}      { BEGIN COMMENT;
                   temp1=temp1+yytext;
                   c=line_count;
            
          }

<COMMENT>[^\n]  {       temp1=temp1+yytext;
			
			
			}
<COMMENT>{EXTEND} {line_count++;
                    temp1=temp+yytext;
                   
                  }

<COMMENT>{NEWLINE} { line_count++;
                     fprintf(logout,"Line no %d: TOKEN <COMMENT> Lexeme %s found\n\n",c,temp1.c_str());
                     BEGIN INITIAL;
                     temp1="";
           
                   }

"/*"      	{ 
			BEGIN (MYSTATE);
                        temp=temp+yytext;
			c=line_count;
			
		}

<MYSTATE>{NEWLINE}     {
			line_count++;			
			//fprintf(logout,"%s",yytext);
                        temp=temp+yytext;
			}


<MYSTATE>"*/"    {      temp=temp+yytext;
			fprintf(logout,"Line no %d: TOKEN <COMMENT> Lexeme %s found\n\n",c,temp.c_str());
			BEGIN INITIAL;
                        temp="";
                        //fprintf(logout,"%s",temp.c_str());
                        
			
			}
<MYSTATE>[^\n]  {       temp=temp+yytext;
			//fprintf(logout,"%s",yytext);
			
			}

<MYSTATE><<EOF>> 	{
                        fprintf(logout,"Error at line no %d: Unterminated comment %s\n\n",c,temp.c_str());
                        error_count++;
			fprintf(logout,"Total Line Number: %d\n\n",line_count-1); 
			fprintf(logout,"Total Errors: %d\n",error_count);
			
			return 0;
			}







<<EOF>> 	{
			fprintf(logout,"Total Line Number: %d\n\n",line_count-1); 
			fprintf(logout,"Total Errors: %d\n",error_count);
			return 0;
			}





.        {fprintf(logout,"Line no %d:Unrecognized character %s found\n\n",line_count,yytext);}





			

%%

int main(int argc,char *argv[]){
	
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	logout= fopen("log.txt","w");
	tokenout= fopen("token.txt","w");

	yyin= fin;
	yylex();
	fclose(yyin);
	fclose(tokenout);
	fclose(logout);
	return 0;
}
