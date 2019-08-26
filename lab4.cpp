#include<bits/stdc++.h>
#include<string>
using namespace std;

struct et 
{ 
    string value; 
    et* left, *right; 
}; 

int toInt(string s)  
{  
    int num = 0;  
     
        for (int i=0; i<s.length(); i++)  
            num = num*10 + (int(s[i])-48);  
      
    return num;  
}  



int eval(et* root)  
{  
    
    if (!root)  
        return 0;  
  
  
    if (!root->left && !root->right)  
        return toInt(root->value);  
  
     
    int l_val = eval(root->left);  
  
      
    int r_val = eval(root->right);  
   string w=root->value;
      
    if (w[0]=='+')  
        return l_val+r_val;  
  
    if (w[0]=='-')  
        return l_val-r_val;  
  
    if (w[0]=='/')  
        return l_val*r_val; 

    if (w[0]=='*')  
        return l_val*r_val;   
     if(w[0]=='^')
         return pow(l_val,r_val);
    return l_val/r_val;  
}  

  

int isOperator(string s)
{if(s[0]=='+'||s[0]=='*'||s[0]=='-'||s[0]=='/'||s[0]=='^')
return(1);
else
return(0);}

et* newNode(string v) 
{ 
    et *temp = new et; 
    temp->left = temp->right = NULL; 
    temp->value = v; 
    return temp; 
}; 

et* constructTree(vector<string> j) 
{ 
    stack<et *> st; 
    et *t, *t1, *t2; 
   
    for (int i=0; i<j.size(); i++) 
    { 
        
        if (!isOperator(j[i])) 
        { 
            t = newNode(j[i]); 
            st.push(t); 
        } 
        else 
        { 
            t = newNode(j[i]); 
   
            t1 = st.top(); 
            st.pop();     
            t2 = st.top(); 
            st.pop(); 
  
          
            t->right = t1; 
            t->left = t2; 
  
           
            st.push(t); 
        } 
    } 
  
    t = st.top(); 
    st.pop(); 
  
    return t; 
} 


int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 



vector <string> intopo(string s)
{ stack<string> st;
string x;
st.push(x);
vector<string> ns;
for(int i = 0; i < s.length(); i++) 
    {  string q="";
       string r;
      while(s[i] >= '0' && s[i] <= '9')
         {  
            q.push_back(s[i]);
            i++;  }
          ns.push_back(q);
         q.clear();

 
        
        if(s[i]=='+'||s[i]=='/'||s[i]=='*'||s[i]=='-'||s[i]=='^'){ string f=st.top();
               char c=f[0];
            while(st.top() != x && prec(s[i]) <= prec(c)) 
            { 
                string h = st.top(); 
                st.pop(); 
               char c=h[0];
                ns.push_back(h);
            } 
            string r="";
         r.push_back(s[i]);
         st.push(r);
        } }
         while(st.top() != x) 
           { 
        string c = st.top(); 
        st.pop(); 
        ns.push_back(c);
            } 
               
  return ns;
    } 


int main()
{ int k,l;
cin>>k;
for(l=0;l<k;l++)
{string o;
cin>>o;
vector<string> j = intopo(o);
int i;
et* a = constructTree(j) ;
int num = eval(a);
cout<<num<<endl;}
}


