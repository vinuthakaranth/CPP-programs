			 /* breadth first search */
#include<iostream.h>
#include<conio.h>

int q[20],size=-1;

int search(int x)
{
 for(int i=0;i<=size;i++)
 {
    if(q[i]==x)
     return 0;
 }
return 1;
}

void insert(int x)
{
size++;
q[size]=x;
}

void main()
{
int adj[10][10] ,n,r=0,x;
cout<<"enter the number of vertices"<<endl;
cin>>n;
cout<<"enter the elements"<<endl;
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
cin>>adj[i][j];
cout<<"enter the start vertex"<<endl;
cin>>x;
x--;
insert(x);
cout<<"join"<<endl;
while(r<=size)
{
for(i=0;i<n;i++)
{
     if(adj[x][i] && search(i))
      {
	insert(i);
	cout<<x+1<<" & "<<i+1<<"\n";
      }
}
r++;
x=q[r];
}
getch();
}