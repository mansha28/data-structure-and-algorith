#include<iostream>
#include<cmath>
using namespace std;
struct node{
int x;
int y;
struct node *ptr;
};
struct node *str=NULL;
struct node *createNode()
{struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	return temp;
}

void addFirst(int a, int b)
{
	struct node *newnode;
	newnode = createNode();
	if(newnode == NULL)
	{
		cout<<"cannot create newNode.";
		return ;
	}
	newnode->x =a;
	newnode->y=b;
	newnode->ptr=str;
	str=newnode;
}
void DelFirst(){
struct node *temp;
	if(str ==NULL) return;
	else {
		temp =str;
		str = (str)->ptr;
		free(temp);
	}
}
void Del(int a,int b)
{
   struct node *temp, *prev;
temp= str;
while(temp->ptr != NULL)
{prev=temp;
if((temp->x==a)||(temp->y==b))    
{prev->ptr=temp->ptr;
	free(temp);
temp=temp->ptr;
}
else
temp=temp->ptr;
}
}
void Search(int d)
{
struct node *temp;
temp=str;
int count=0;
while(temp->ptr!=NULL)
{
if(sqrt((temp->x)*(temp->x)+(temp->y)*(temp->y))>d) temp=temp->ptr;
else {count++; temp=temp->ptr;}
cout<<count;
}
}

bool bsearch(int a, int b)
{
struct node *temp;
temp = str;
while(temp->ptr!=NULL)
{
if((temp->x==a)||(temp->y==b)) return true;
else temp=temp->ptr;
}
return false;
}
void length()
{
struct node *temp;
int count=0;
temp=str;
while(temp->ptr!=NULL)
{
count++;
temp=temp->ptr;
cout<<count;
}
}
int main()
{
int p,m,n;
float d;
do
{
cin>>p;
if(p==1) {cin>>m>>n; addFirst(m,n);}
else if(p==2) DelFirst();
else if(p==3) {cin>>m>>n; Del(m,n);}
else if(p==4) { cin>>d; Search(d);}
else if(p==5) { cin>>m>>n; bsearch(m,n);}
else if(p==6) length();
return 0;
}while((p>=1)||(p<=6));
}

