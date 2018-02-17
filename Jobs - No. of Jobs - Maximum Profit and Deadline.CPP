
#include <iostream.h>
#include <conio.h>

int j[10],p[10],d[10],n;

void sort()
{
	for(int i=1;i<=n;i++)
	for(int k=i+1;k<=n;k++)
	if(p[i]<p[k])
	{
		int temp=p[i];
		p[i]=p[k];
		p[k]=temp;

	}
	for(i=1;i<=n;i++)
		j[i]=p[i];
}


void calculate()
{
	j[0]=d[0]=0;
	j[1]=1;
	int k=1;
	for(int i=2;i<=n;i++)
	{
		int r=k;
		while(d[j[r]]>d[i] && d[j[r]]!=r)
		r--;
		if(d[j[r]]<=d[i] && d[i]>r)
		{
			for(int l=k;l>=r+1;l--)
				j[l+1]=j[l];
			j[r+1]=i;
			k++;
		}
	}

	int max=0;
	for(i=1;i<=k;i++)
	{
		cout<<"\n"<<j[i]<<"\t"<<p[j[i]];
		max+=p[j[i]];
	}
	cout<<"\nMaximum profit = "<<max;
}

void main()
{
	clrscr();
	cout<<"\nEnter the no of jobs";
	cin>>n;
	cout<<"\nEnter the profit and deadline";
	for(int i=1;i<=n;i++)
	cin>>p[i]>>d[i];
	sort();
	calculate();
	getch();
}


