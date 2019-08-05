#include<iostream>
#include<cmath>
using namespace std;
struct node{
int x;
int y;
struct node *next;
};
struct node *start=NULL;


void addfirst(int a,int b)
{
struct node *temp=new node;
temp->x=a;
temp->y=b;
temp->next=NULL;
if(start==NULL)
{ start=temp;}
else{temp->next=start;
    start=temp;}
}   
void delfirst()
{struct node *temp;
temp=start;
start=temp->next;
delete temp;
}

void del(int a,int b)
{ struct node *temp,*prev;
 temp=start;
if (temp != NULL && (temp->x==a&&temp->y==b)) 
    { 
        start = temp->next;  
        delete temp;        
              return; 
    } 

while (temp != NULL && (temp->x==a&&temp->y==b)) 
    { 
        prev = temp;              
        temp = temp->next; 
    }
   if (temp == NULL) return;
   prev->next = temp->next; 
   delete temp;
}

void search(float d)
{ int x,y;
  struct node *temp;
  temp=start;
  while(temp!=NULL)
  {
 float r=sqrt((temp->x)*(temp->x)+(temp->y)*(temp->y));
  if(r<=d)
 {  cout<<"("<<temp->x<<","<<temp->y<<")"; }
  temp=temp->next;
 }
}

bool search(int a,int b)
{ struct node *temp;
  temp=start;
    while (temp != NULL)  
    {  
        if (temp->x == a && temp->y == b)  
            return true;  
        temp = temp->next;  
    }  
    return false;

}

int length()
{struct node *temp;
 temp=start;
int n=0; 
 while(temp!=NULL)
  { n=n+1;
   temp=temp->next;
     }
cout<<"lenght:"<<n;
return 0;
}

int main()
{
int p,m,n;
float d;


for(int i=0; ;i++)
{
cin>>p;
if(p==0||p>6) break;
else if(p==1) {cin>>m>>n; addfirst(m,n);}
else if(p==2) delfirst();
else if(p==3) {cin>>m>>n; del(m,n);}
else if(p==4) { cin>>d; search(d);}
else if(p==5) { cin>>m>>n; if(search(m,n)) cout<<true;
                else cout<<false;}
else if(p==6) length();
}
}








