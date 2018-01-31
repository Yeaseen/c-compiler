#include<bits/stdc++.h>

using namespace std;


int main()
{
    map<string,int> mp;

    for(int i=0;i<=10;i++)
    {


    string name;
    cin>>name;
    int counter=0;

    if(mp.find(name)==mp.end()) mp[name]++;
    else mp[name]=counter;

    cout<<mp.begin()->first;

    cout<<mp.begin()->second;
    cout<<endl;

    }

}
