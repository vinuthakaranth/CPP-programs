		      /* depth first search */
#include<iostream.h>
#include<conio.h>

int a[10][10],reach[10]={0},n;

void dfs(int s)
{
cout<<"  "<<s;
reach[s]=1;
for(int i=1;i<=n;i++)
if(a[s][i]!=0 && !reach[i])
dfs(i);
}

void main()
{
clrscr();
cout<<"enter the number of vertices"<<endl;
cin>>n;
cout<<"enter the elements"<<endl;
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
cin>>a[i][j];

	cout<<"enter the start vertex";
	int s;
	cin>>s;
	dfs(s);
	getch();
}