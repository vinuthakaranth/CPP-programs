#include<iostream.h>
#include<conio.h>
#define INF 1000

  int n,s,a[10][10],prev[10],dist[10];

  void sssp()
   {
     int checked[10],min,u;

     for(int i=0;i<n;i++)
      {
       checked[i]=0;
       dist[i]=a[s][i];
       if(dist[i]<INF)
	 prev[i]=s;
       else
	 checked[i]=-1;
       }

      for(i=0;i<n;i++)
	{
	  min=INF;
	  for(int j=0;j<n;j++)
	    if(!checked[j] && dist[j]<min)
	     {
	       min=dist[j];
	       u=j;
	     }

	  checked[u]=1;

	  for(j=0;j<n;j++)
	    if(checked[j]!=1 && dist[j]>a[u][j]+dist[u])
	      {
		dist[j]=a[u][j]+dist[u];
		checked[j]=0;
		prev[j]=u;
	      }
      }
     }



  void main()
   {
     clrscr();

     cout<<"enter the number of vertices :";
     cin>>n;

     cout<<"enter the cost adjacency matrix"<<endl;
     for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	 {
	   cin>>a[i][j];
	   if(a[i][j]==0) a[i][j]=INF;
	 }

      for(i=0;i<n;i++)
	prev[i]=-1;

     cout<<"vertices are number 1 to "<<n<<endl;
     cout<<"enter start vertex :";
     cin>>s;
     s--;

     sssp();

     for(i=0;i<n;i++)
       if(i!=s)
	{
	  cout<<s+1<<"->"<<i+1<<":";
	  if(dist[i]==INF)
	   {
	     cout<<"No Path";
	   }
	  else
	   {
	     cout<<dist[i]<<"\t";
	     cout<<"Path "<<i+1;
	     for(int j=i;prev[j]!=s;j=prev[j])
	      cout<<"<-"<<prev[j]+1;
	     cout<<"<-"<<s+1<<endl;
	   }
	}
 getch();
}


