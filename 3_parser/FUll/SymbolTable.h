#ifndef SymbolTable_h
#define SymbolTable_h
extern FILE *logout;

#include<bits/stdc++.h>

using namespace std;
//extern FILE *logout;


class var
{
public:
int c;
int ival;
float fval ;
int iarray[100];
int arraysize;
int arrayl;
int arraypos;
float farray[100];
};




class SymbolInfo
{
        public:
               string name;
               string type;
               var value;
               int f[20];
               int para=0;
               int fsize;
               int funi=7;
               float funf=4.0;
               int fsign=-1;
               int isF=0;
               

               SymbolInfo* next;

               SymbolInfo(string name,string type,int ival,float fval,int arraysize,int arraypos,int iarrayv,float farrayv,int c)
               {
                   this->name=name;
                   this->type=type;
                   this->next=NULL;
                   this->value.arraysize=arraysize;
                   this->value.c=c;
                 if(c==0) {this->value.ival=ival;}
                else if(c==1) {this->value.fval=fval;}
                else if(c==2) {
                               for(int j=0;j<arraysize;j++) {this->value.iarray[j]=-1;}

                              }
               else if(c==3) {
                              for(int j=0;j<arraysize;j++) {this->value.farray[j]=-1;}

               }
               }

               SymbolInfo()
               {
                   this->name="";
                   this->type="";
                   this->next=NULL;
               }

               SymbolInfo(string name,string type)
               {
                  this->name=name;
                  this->type=type;
                }


};



class ScopeTable
{
     public:
         SymbolInfo** htable;



     public:
         int range;
         ScopeTable* parentScope;
         int scope_id;

         ScopeTable(int range, int id)
         {
             this->range=range;
             htable= new SymbolInfo*[range];
             for(int i=0;i<range;i++) {htable[i]=new SymbolInfo();} //htable[i]->name="" ; htable[i]->type=""; htable[i]->next=NULL;}
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

        void Insert(string name, string type, int ival, float fval, int arraysize,int arraypos,int iarrayv, float farrayv, int c)
        {
        
/*
            SymbolInfo* entry= htable[t]->next;

            while(entry!=NULL)
            {
                if(entry->name==name)
                {
                    k=1;
                    //if(c==0) {entry->value.ival=ival;}
                    //else if(c==1) {entry->value.fval=fval;}
                    //else if(c==2) {entry->value.iarray[arraypos]=iarrayv;}
                    //else if(c==3) {entry->value.farray[arraypos]=farrayv;}
                    break;
                }
                entry=entry->next;
            }
*/
            //if(k==0)
            
            int hash_val=HashFunc(name);

            SymbolInfo* entry = htable[hash_val];

             //int p=0;

            while(entry->next!=NULL)
            {


                entry=entry->next;
                //p++;
            }

            if (entry->next == NULL)
            {
                entry->next = new SymbolInfo(name,type,ival,fval,arraysize,arraypos,iarrayv,farrayv,c);

            }
            
        }




        void PA()
        {

            //fprintf(logout,"Scopetable--> %d \n",scope_id);
            //cout<<"Scopetable--> "<<scope_id<<endl;
            fprintf(logout,"ScopeTable--> %d \n",scope_id);
            for(int i=0;i<range;i++)
            {


            SymbolInfo* entry= htable[i]->next;

            if(entry!=NULL)
            {
            while(entry!=NULL)
            {
                char a[250];
		std::string s = "<" + entry->name + "," + entry->type + ",";
		strcpy(a,s.c_str());
		a[sizeof(a) - 1] = 0;
		//fprintf(logout,"<%s,%s,%d",entry->getName(),entry->getType(),entry->value.c);
                        
		       //cout<<"<"<<entry->name<<","<<entry->type<<",";
                       fprintf(logout,"%s",a);
                if(entry->value.c==0) fprintf(logout,"%d",entry->value.ival); //cout<<entry->value.ival;
                if(entry->value.c==1) fprintf(logout,"%f",entry->value.fval); //cout<<entry->value.ival;
                if(entry->value.c==2) { fprintf(logout,"{");//cout<<"{";
                       for(int i=0;i<entry->value.arraysize;i++) {
                       if(i!=entry->value.arraysize-1) fprintf(logout,"%d,",entry->value.iarray[i]);//cout<<entry->value.iarray[i]<<",";
                       else fprintf(logout,"%d",entry->value.iarray[i]);
                }
                fprintf(logout,"}");//cout<<"}";
                }
                if(entry->value.c==3) { fprintf(logout,"{"); //cout<<"{";
                       for(int i=0;i<entry->value.arraysize;i++) {
                       if(i!=entry->value.arraysize-1) fprintf(logout,"%f,",entry->value.farray[i]);//cout<<entry->value.iarray[i]<<",";
                       else fprintf(logout,"%f",entry->value.farray[i]);
                }

                fprintf(logout,"}");//cout<<"}";
                }
                if(entry->value.c==-3) fprintf(logout,"%d",entry->fsign);
                if(entry->para==1) { fprintf(logout,"{"); //cout<<"{";
                       for(int i=0;i<entry->fsize;i++) {
                       if(i!=entry->fsize-1) fprintf(logout,"%d,",entry->f[i]);//cout<<entry->value.iarray[i]<<",";
                       else fprintf(logout,"%d",entry->f[i]);
                }
                fprintf(logout,"}");//cout<<"}";
                }









 
                fprintf(logout,">");//cout<<">"<<endl;
                entry=entry->next;
            }
             fprintf(logout,"\n");
            }
            }

          fprintf(logout,"\n");

        }

        SymbolInfo* LU(string name)
        { int k=0;
            int hash_val=HashFunc(name);

            SymbolInfo* entry= htable[hash_val]->next;

            int p=0;

            while(entry!=NULL)
            {
                if(entry->name==name)
                {
                    k=1;
                    //111cout<<"found in Scopetable#" <<scope_id<<" at position: "<<hash_val<<","<<p;
                    return entry;

                }
                p++;
                entry=entry->next;
            }

            if(k==0) {
                    //cout<<"doesnt exist in the scope id: "<<scope_id<<endl;
                    return NULL;
                      }

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

         void EntryScope()
         {
             ScopeTable* temp=new ScopeTable(range,stable->scope_id+1);
             temp->parentScope=stable;
             stable=temp;
             cout<<"new scopeTable created with id " <<stable->scope_id;

         }

         void ExitScope()
         {
             ScopeTable* temp= stable;
             stable=stable->parentScope;
             delete(temp);

         }


/*         void InsertS(string name, string type)
         {
             stable->Insert(name, type);
         }

*/
         void InsertS(string name,string type,int ival,float fval,int arraysize,int arraypos,int iarrayv,float farrayv,int c)
         {
             stable->Insert(name,type,ival,fval,arraysize,arraypos,iarrayv,farrayv,c);
         }


         void PrintCurrent()
         {
             stable->PA();
         }

         void AllScopePrint()
         {
             ScopeTable* run=stable;

             while(run->parentScope!=NULL)
             {
                 run->PA();
                 cout<<endl;
                 run=run->parentScope;
             }
             if(run->parentScope==NULL) {run->PA();}


         }

         SymbolInfo* Look(string name)
         {
             SymbolInfo* temp= stable->LU(name);
             return temp;
         }

         SymbolInfo* LookAll(string name)
         {
             ScopeTable* run=stable;
             SymbolInfo* temp;

             while(run->parentScope!=NULL)
             {
                 temp=run->LU(name);
                 if(temp) return temp;

                 run=run->parentScope;
             }
             if(run->parentScope==NULL) {return run->LU(name);}

         }




};






#endif // SymbolTable_h
