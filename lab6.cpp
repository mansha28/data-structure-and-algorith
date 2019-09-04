#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
    int n,q,max,t,ammount;
    int a,id;
    cin>>n>>q;
    max=0;
    vector <int> userid;
    t=0;
    userid={0};
    for(int i=0;i<q;i++)
    {
        cin>>a;
        switch(a)
        {
            case 1: cin>>id>>ammount;
                    userid[id]+=ammount;
                    if(userid[id]>max)
                    {
                        max=userid[id];
                        t=id;
                    }
                    break;
            case 2: if(t==0) cout<<"No data available ";
                    else cout<<t;
                    break;
            default : cout<<"choice is other than 1 or 2";
                        break;        
        }
    }
}
