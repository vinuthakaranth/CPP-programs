#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>

void selection_sort(int a[],int n)
{
int small,pos,temp,j;
for(int i=0;i<n;i++)
{
small=a[i];
pos=i;
for(j=i+1;j<n;j++)
if(a[j]<small )
{
small=a[j];
pos=j;
}
temp=a[pos];
a[pos]=a[i];
a[i]=temp;

} }
void main()
{
	int a[10000],i,n;
	clrscr();
	 clock_t strt,end;


	 n=6000  ;
	 for(i=0;i<n;i++)

	   a[i]=rand();
	 strt=clock();
	 selection_sort(a,n);
	end=clock();
	 cout<<"time taken to sort"<<(end-strt)/CLK_TCK<<endl;
		       getch();
		 cout<<"sorted array"<<endl;
	     for(i=0;i<n;i++)
	     cout<<" "<<a[i];
	     getch();

}