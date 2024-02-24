#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;


class SymbolInfo
{
    public:
        string name;
        string type;
        //int key;
        //int key_id;

        SymbolInfo* next;

        SymbolInfo(string name, string type)
        {
            //this->key=key;
            this->name=name;
            this->type=type;
            //key_id=0;
            this->next=NULL;
        }
        SymbolInfo()
        {
            //this->key=key;
            this->name="";
            this->type="";
            //key_id=0;
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
                if(entry->name==name)
                {
                    k=1;
                    cout<<"already inserted";
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



            cout<<"Inserted in Scopetable#" <<scope_id<<"  at Position  " <<hash_val<<", "<<p;

            }


        }
        void PA()
        {
            cout<<"Scopetable "<<scope_id<<endl;
            for(int i=0;i<range;i++)
            {


            SymbolInfo* entry= htable[i]->next;
            cout<<i<<"-->  ";
            while(entry!=NULL)
            {
                cout<<"<"<<entry->name<<" : "<<entry->type<<">"<<" ";
                entry=entry->next;
            }
            cout<<endl;
            }
        }
        void LU(string name)
        { int k=0;
            int hash_val=HashFunc(name);

            SymbolInfo* entry= htable[hash_val]->next;

            int p=0;

            while(entry!=NULL)
            {
                if(entry->name==name)
                {
                    k=1;
                    cout<<"found in Scopetable#" <<scope_id<<" at position: "<<hash_val<<","<<p;
                    break;
                }
                p++;
                entry=entry->next;
            }

            if(k==0) cout<<"doesnt exist in the scope id: "<<scope_id<<endl;

        }



        void Delete(string name)
        {
            int k=0;
            int t=HashFunc(name);


            SymbolInfo* entry= htable[t]->next;

            while(entry!=NULL)
            {
                if(entry->name==name)
                {
                    k=1;
                    break;
                }
                entry=entry->next;
            }

            if(k==1)
            {


            int hash_val=HashFunc(name);


            SymbolInfo* temp;
            SymbolInfo* head=htable[hash_val];

             int p=0;

            while(head->next!=NULL)
                {
                    if(head->next->name==name)
                    {
                        temp=head->next;


                        head->next=head->next->next;
                        delete(temp);
                        cout<<"deleted in Scopetable#" <<scope_id<<"  at "<<hash_val<<","<<p;
                        break;
                    }
                    head=head->next;
                    p++;

                 }


        }
        if(k==0) cout<<"Not Found in the scope";
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
            stable=new ScopeTable(range,0);
         }


         void EntryScope()
         {
             ScopeTable* temp=new ScopeTable(range,stable->scope_id+1);
             temp->parentScope=stable;
             stable=temp;
             cout<<"new scopeTable created with id " <<stable->scope_id;

         }

         void ExitSxope()
         {
             ScopeTable* temp= stable;
             stable=stable->parentScope;
             delete(temp);

         }

         void InsertS(string name,string type)
         {
             stable->Insert(name,type);
         }

         void RemoveS(string name)
         {
             stable->Delete(name);
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
         void Look(string name)
         {
             ScopeTable* run=stable;

             while(run->parentScope!=NULL)
             {
                 run->LU(name);

                 run=run->parentScope;
             }
             if(run->parentScope==NULL) {run->LU(name);}

         }





};













int main()
{
    int range;
    cin>>range;

    SymbolTable ob(range);

    for(int i=0;i<100;i++)
    {


    char choice;
    cin>>choice;

    if(choice=='S')
    {
        ob.EntryScope();
    }
    if(choice=='E')
    {
        ob.ExitSxope();
    }

    if(choice=='I')
    {
        string name,type;
        cin>>name;
        cin>>type;
        ob.InsertS(name,type);
    }

    if(choice=='P')
    {
        char al;
        cin>>al;
        if(al=='A')
        {
            ob.AllScopePrint();
        }
        else if(al='C')
        {
            ob.PrintCurrent();
        }
    }

    if(choice=='L')
    {
        string name;
        cin>>name;
        ob.Look(name);
    }

    if(choice=='D')
    {
        string name;
        cin>>name;
        ob.RemoveS(name);
    }
    }


}


