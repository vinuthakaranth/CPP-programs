//PROGRAM TO IMPLEMENT TOPOLOGICAL SORTING
#include<iostream.h>
#include<conio.h>
#include<process.h>
int a[10][10],adj[10][10],n,reach[10]={0},start;

  void dfs(int s)
 {
  if(start!=s)
  {
  a[start][s]=1;
  }
  reach[s]=1;
  for(int i=0;i<n;i++)
  if(adj[s][i]!=0&&!reach[i])
  dfs(i);
 }
void main()
 {
  clrscr();
  cout<<"\nEnter the number of verticies :";
  cin>>n;
  cout<<"\nEnter the adjacency matrix :\n";
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
  cin>>adj[i][j];
  /*checking for cycles*/
  for(start=0;start<n;start++)
  dfs(start);

 for(i=0;i<n;i++)
 for(j=0;j<n;j++)
 if(a[i][j]==1&&a[j][i]==1)
   {
     cout<<"This graph contains cycles";
     getch();
     exit(0);
   }
   int index[10];
   for(i=0;i<n;i++)
   index[i]=0;
   for(i=0;i<n;i++)
   for(j=0;j<n;j++)
   index[i]+=adj[j][i];

   int sol[10],k=0;
   while(k<n-1)
    {
     for(i=0;i<n;i++)
      {
       if(index[i]==0)
	{
	   sol[k]=i+1;
	   k++;
	   index[i]=-1;
	 for(int l=0;l<n;l++)
	 if(adj[i][l]==1)
	  index[l]-=1;
	}
      }
     }

   cout<<"\nTopological Sequence :\n";
   for(i=0;i<n;i++)
    cout<<" "<<sol[i];
    getch();
  }




