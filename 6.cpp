#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n,q,max,t,ammount;
    cin>>n>>q;
    max=0;
    int userid[q];
    t=0;
    for(int i=1;i<=n;i++) userid[i]=0;
    for(int i=1;i<=q;i++)
    {
        int a,id;
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
            case 2: if(t==0) cout<<"No data available";
                    else cout<<t;
                    break;
                    
        }
    }
}