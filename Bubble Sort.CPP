#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>

void bubble_sort  (int a[],int n)
{
int temp;
for(int i=1;i<n;i++)
for(int j=0;j<n-i;j++)
if(a[j]>=a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
void main()
{
	int a[10000],i,n;
	clrscr();
	 clock_t strt,end;


	 n=8000  ;
	 for(i=0;i<n;i++)

	   a[i]=rand();
	 strt=clock();
     bubble_sort(a,n);
	end=clock();
	 cout<<"time taken to sort"<<(end-strt)/CLK_TCK<<endl;
		       getch();
		 cout<<"sorted array"<<endl;
	     for(i=0;i<n;i++)
	     cout<<" "<<a[i];
	     getch();

}