#include<stdio.h>
#include<iostream.h>
#include<conio.h>

void sort(int p[],int tb[],int n);
void job(int p[],int d[],int tb[],int n);

void main()
{
clrscr();
int n;
cout<<"Enter the number of jobs:";
cin>>n;
int *p=new int [n+1];
int *d=new int [n+1];
int *tb=new int [n+1];
cout<<"\nEnter the profits:\n";
for(int i=1;i<=n;i++)
     cin>>p[i];
cout<<"\nEnter the deadlines:\n";
for(i=1;i<=n;i++)
     cin>>d[i];
for(i=1;i<=n;i++)
    tb[i]=i;
sort(p,tb,n);
job(p,d,tb,n);
getch();
}

void sort(int p[],int tb[],int n)
{
int temp1,temp2;

for(int i=1;i<=n;i++)
     for(int j=1;j<=n-i;j++)
	{
	     if(p[j]<p[j+1])
	     {
		  temp1=p[j];
		  p[j]=p[j+1];
		  p[j+1]=temp1;

		  temp2=tb[j];
		  tb[j]=tb[j+1];
		  tb[j+1]=temp2;
	     }
	}

}

void job(int p[],int d[],int tb[],int n)
{
int *j=new int [n+1];
j[0]=d[0]=0;
j[1]=tb[1];
int cost=p[1];
int k=1;
int r;

for(int i=2;i<=n;i++)
{
    r=k;
    while(d[j[r]]>d[tb[i]] && d[j[r]]!=r)    r--;
    if(d[j[r]]<=d[tb[i]] && d[tb[i]]>r)
    {
	for(int q=k;q>r;q--)
	     j[q+1]=j[q];
	     j[q+1]=tb[i];
	     k++;
	     cost+=p[i];
    }
}

cout<<"\nThe optimal processing sequence is:\n";
for(i=1;i<=k;i++)
     cout<<j[i]<<"\t";
cout<<"\nOptimal profit:"<<cost;
}

