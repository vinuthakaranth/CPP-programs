#include<iostream.h>
#include<conio.h>
#include<process.h>

void main()
{
int a[10][10],n,p[10][10];
 cout<<"enter the vertices"<<endl;
 cin>>n;
 cout<<"enter the elements"<<endl;
 for(int i=0;i<n;i++)
 for(int j=0;j<n;j++)
{
cin>>a[i][j];
 p[i][j]=a[i][j];
 }
 for (int k=0;k<n;k++)
 for( j=0;j<n;j++)
 for( i=0;i<n;i++)
 if( p[i][k] && p[k][j]||p[i][j])
 p[i][j]=1;

 for( j=0;j<n;j++)
 for( i=0;i<n;i++ )
 if(p[i][j]==0)
 {
 cout<<"disconnected"<<endl;
 exit(0);
 }
 cout<< "connected"<<endl;
 }