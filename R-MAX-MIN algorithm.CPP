#include<iostream.h>
#include<conio.h>

int max=0;

int rmax(int a[],int n)
{
if(n<0)
return max;

if(a[n]>max)
{
	max=a[n];
	return(rmax(a,n-1));
}
 else
 return(rmax(a,n-1));
 }


int rmin(int a[],int n,int small)
 {

 if(n<0)
 return small;

 if(a[n]<small)
 {
	small=a[n];
	return(rmin(a,n-1,small));
 }
 else
 return(rmin(a,n-1,small));
}

void main()
{
int a[10],n;
clrscr();
cout<<"enter the size"<<endl;
cin>>n;
cout<<"enter the array"     <<endl;
for(int i=0;i<n;i++ )
cin>>a[i];
int res=rmax(a,n-1);
int min=rmin(a,n-1,a[0]);
cout<<endl<<"maximum="<<res<<endl<<"minimum="<<min;
getch();
}