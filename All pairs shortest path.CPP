		      /*All pairs shortest path*/
#include<iostream.h>
#include<conio.h>
int c[10][10],kay[10][10],adj[10][10],n;
void apsp();
void shortest(int ,int) ;
void outputpath(int ,int);
void findckay();

void main()
{
clrscr();
cout<<"enter no of vertices"<<endl;
cin>>n;
cout<<"enter adjacency matrix"<<endl;
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
{
cin>>adj[i][j];
c[i][j]=adj[i][j];
kay[i][j]=0;
}
apsp();
getch();
}

void apsp()
{
findckay();
cout<<"All pair shortest paths :"<<endl;
for(int i=1;i<=n;i++)
{
getch();
cout<<endl<<"Shortest path from vertex"<<i;
for(int j=1;j<=n;j++)
shortest(i,j);
}
}
void findckay()
{
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
for(int k=1;k<=n;k++)
{
 int t1=c[i][k];
 int t2=c[k][j];
 int t3=c[i][j];
 if(t1!=0&&t2!=0&&(t3==0||t1+t2<t3))
 {
 c[i][j]=t1+t2;
 kay[i][j]=k;
 }
 }
 }

 void shortest(int i,int j)
 {
 if(c[i][j]==0)
 {
 cout<<"\n There is no path from "<<i<<"to"<<j;
 return;
 }
 cout<<endl<<i<<" ";
 outputpath(i,j);
 }

 void outputpath(int i,int j)
 {
 if(i==j)
 return;
 if(kay[i][j]==0)
 cout<<j<<" ";
 else
 {   outputpath(i,kay[i][j]);
     outputpath(kay[i][j],j);
 }
}