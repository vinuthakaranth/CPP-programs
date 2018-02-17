#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
void insertion_sort(int a[],int n)
{
int temp ,j;
for(int i=1;i<n;i++)
     {
temp=a[i];
j=i-1;
while(j>=0 && temp<a[j] )
{
a[j+1]=a[j];
j--;
}
a[j+1]=temp;
     }
}

void main()
{
	int a[50],i,n;
	clrscr();
	 clock_t strt,end;

	 cout<<endl<<"enter the number of elements";
	 cin>>n;
	 cout<<"enter rhe elements"<<endl;
	 for(i=0;i<n;i++)
	 cin>>a[i];

	 strt=clock();
	 insertion_sort(a,n);
	 delay(2000);
	 end=clock();
	 cout<<"time taken to sort"<<(end-strt)/CLK_TCK<<endl;

		 cout<<"sorted array"<<endl;
	     for(i=0;i<n;i++)
	     cout<<" "<<a[i];
	     getch();
}