#include <iostream>
#include <cstdlib>


using namespace std;


int main()
{

    int low=0;
    int range =7;

    for(int i=0;i<10;i++)
    {
        int ri=low + rand()%range;
        cout<<ri<<endl;
    }
}
