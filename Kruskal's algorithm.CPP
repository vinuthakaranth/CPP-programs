#include<iostream.h>
#include<conio.h>
typedef struct edsets
{
   int x[10],count;
 };

  edsets set[10];
   int si=0,u,v,min,adj[10][10],n;

   int small()
   {
      int l=1000;
       for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
	 if(adj[i][j]!=0 && adj[i][j]<l)
	   {
	     l=adj[i][j];
	     u=i,
	     v=j;
	    }
	  adj[u][v]=adj[v][u]=0;
	  return (l);
    }


    int det(int uv)
     {
       for(int i=0;i<si;i++)
	 if(set[i].count>0)
	    for(int j=0;j<set[i].count;j++)
	       if(set[i].x[j]==uv)
		  return i;
		    return -1;
      }


     void merge(int x1,int x2)
      {
	   int i2=set[x2].count;
	   for(int i=0;i<i2;i++)
	       {
		   set[x1].x[set[x1].count]=set[x2].x[i];
		   set[x1].count++;
		   set[x2].count=-1;
		   set[x2].x[i]=-1;
		}
       }



       int cycle(int u,int v)
	{
	  int x1=det(u);
	  int x2=det(v);
	  if(x1==-1 && x2==-1)
	    {
	     set[si].x[0]=u;
	     set[si].x[1]=v;
	     set[si].count=2;
	     si++;
	      return 1;
	      }
	     if(x1==-1 && x2>=0)
	      {
		set[x2].x[set[x2].count]=u;
		set[x2].count++;
		return 1;
	      }

	    if(x1>=0 && x2==-1)
	     {
		set[x1].x[set[x1].count]=v;
		set[x1].count++;
		return 1;
	      }

	    if(x1>=0 && x2>=0)
	      {
	       if(x1==x2) return 0;
	       else
		{
		   merge(x1,x2);
		   return 1;
	       }
	      }
	}


	     void kruskal()
	     {
	      int b[10][10];
	      for(int i=0;i<n;i++)
	      for(int j=0;j<n;j++)
		  b[i][j]=0;
	      int ed=0,f=0;
	      while(ed<n-1)
	       {
			int mini=small();
			f=cycle(u,v);
			if(f==1)
			{
				b[u][v]=b[v][u]=mini;
				cout<<endl<<"join"<<u+1<<"and"<<v+1;
				min+=mini;
				ed++;
			}
	      }
	      cout<<endl<<"\nminimum cost tree is";
	      for(i=0;i<n;i++)
	      {
		cout<<endl;
		for(j=0;j<n;j++)
		cout<<"\t"<<b[i][j];
	      }
	     cout<<"\nminimum cost is"<<min;
	      getch();
	    }


	  void main()
	    {
	     clrscr();
	    cout<<"no of vertices";
	    cin>>n;
	    cout<<"adj matrix";
	     for(int i=0;i<n;i++)
	     for(int j=0;j<n;j++)
		 cin>>adj[i][j];
		 kruskal();
	      }


