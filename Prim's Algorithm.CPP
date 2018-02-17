#include <iostream.h>
#include <conio.h>

class prims
{
	int graph[11][11],a[10],mincost,t[11][3],n;
	public:
		prims();
		int cost(int,int);
		void spantree();
		void getdata();
		int min();
};

prims :: prims()
{
	mincost=0;
	cout<<"\nEnter the no of vertices";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		graph[i][j]=t[i][1]=t[i][2]=100;
		a[i]=1;
	}
}

void prims :: getdata()
{
	int **a;
	a=new int*[n+1];
	for(int i=1;i<=n;i++)
	a[i]=new int[n+1];
	cout<<"\nEnter the matrix";
	for(i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		cin>>a[i][j];
		if(a[i][j]!=0)
		graph[i][j]=a[i][j];
	}
}

int prims :: cost(int i,int j)
{
	return(graph[i][j]);
}

int prims :: min()
{
	int m=100,j=-1;

	for(int i=2;i<=n;i++)
	{       if(a[i]!=0)
		{
			if(cost(i,a[i])<m)
			{
				m=cost(i,a[i]);
				j=i;
			}
		}
	}
	return(j);
}

void prims :: spantree()
{
	int i,j,k;
	cout<<"\nSpanning tree";
	a[1]=0;
	for(i=1;i<n;i++)
	{
		j=min();
		if(j!=-1)
		{
			t[i][1]=j;
			t[i][2]=a[j];
			mincost+=cost(j,a[j]);
			a[j]=0;
			for(k=1;k<=n;k++)
			{
				if(a[k]!=0)
				if(cost(k,a[k])>cost(k,j))
					a[k]=j;
			}
		}
		else
		{
			cout<<"Disconnected";
			return;
		}
	}
	for(i=1;i<n;i++)
		cout<<endl<<t[i][2]<<"->"<<t[i][1]<<"\n";
	cout<<"\nminimum cost is"<<mincost;
}

void main()
{
	clrscr();
	prims p;
	p.getdata();
	p.spantree();
	getch();
}


