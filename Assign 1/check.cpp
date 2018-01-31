#include <iostream>
using namespace std;



class A
{
public:
    int i;

    A(int i)
    {
        this->i=i;
    }

    int geti()
    {
        return i;
    }


};

int main()
{
    A a(6);

    cout<<a.geti();
}
