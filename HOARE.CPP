#include <conio.h>
#include <iostream.h>
#define MAX 32767

int partition(int,int);
void sort(int,int);

int a[10]={0};

int partition(int low,int high)
{
	int i=low+1,j=high;
	int key=a[low],temp;
	while(1)
	{
		if((i<high) && (key>=a[i]))
			i++;
		if(key<a[j])
			j--;
		if(i<=j)
		{
		       temp=a[i];
		       a[i]=a[j];
		       a[j]=temp;
		}
		else
		{
			temp=a[low];
			a[low]=a[j];
			a[j]=temp;
			return j;
		}
	}
}


void sort(int n,int k)
{
	int low=0,high=n;
	a[n]=MAX;
	while(1)
	{
		int j=partition(low,high);
		if(k==j) return;
		else
		if(k<j) high=j;
		else low=j+1;
	}
}



void main()
{
	clrscr();
	int n;
	cout<<"\nEnter the  size:";
	cin>>n;
	cout<<"\nEnter the elements to be sorted:";
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n;i++)
	sort(n,i);
	cout<<"\nSorted array is :";
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
	getch();
}


