#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
bool balancebrack(string s)
{
stack<char> c;
char x;
for(int i=0;i<s.length();i++)
{
          if(s[i]=='('||s[i]=='{'||s[i]=='['||s[i]=='<')
            { c.push(s[i]); continue;  }
               if(c.empty()) return false;
                 if(s[i]==')'||s[i]=='}'||s[i]==']'||s[i]=='>')
                    {  
                      x = c.top();
                      c.pop();
                      if(x==s[i])
                        {
                          return true;
                          continue;}
                        }
if(s[i]=='|'&&c.empty())
{c.push(s[i]);
continue;}

if(s[i]=='|'&& !c.empty())
{x=c.top();
if(x=='|')
{c.pop();}
if(x!='|')
{c.push('|');}}
if((s[i]=='}'||s[i]==')'||s[i]==']'||s[i]=='>')&& c.empty())
{return false;
break;}
   
}
return (c.empty());
}
int main()
{
int n;
string str[1000];
cin>>n;   //no. of inputs
for(int i=0;i<n;i++){

cin>>str[i];

if(balancebrack(str[i])) cout<<"YES";
else cout<<"NO";
}
return 0;
}
