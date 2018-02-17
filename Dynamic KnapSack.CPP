#include<iostream.h>
#include<conio.h>

int n,w[10],p[10],c;

 int max(int a,int b)
 {
	  return a>b?a:b;
 }

int f(int i,int y)
{
	   if(i==n)
		return(y<w[n]?0:p[n]);
	   if(y<w[i])
		return f(i+1,y);
	   return (max(f(i+1,y),(f(i+1,y-w[i])+p[i])));
}

  void traceback()
  {
	  int x[10];
	  for(int i=1;i<n;i++)
	  {
		  if(f(i,c)==f(i+1,c))
		      x[i]=0;
		  else
		  {
		      x[i]=1;
		      c-=w[i];
		  }
	  }
	  x[n]=(f(n,c))?1:0;
	  cout<<"\n Solution is :";
	  for(i=1;i<=n;i++)
	  cout<<" "<<x[i];
  }

  void main()
  {
	      clrscr();
	      cout<<"\n Enter the no. of articles";
	      cin>>n;
	      cout<<"\n Enter the capacity of sack";
	      cin>>c;
	      cout<<"\n Enter the weights and profits";
	      for(int i=1;i<=n;i++)
	      cin>>w[i]>>p[i];

	      int profit=f(1,c);

	      cout<<"\n Total profit ="<<profit;
	      traceback();
	      getch();
  }



