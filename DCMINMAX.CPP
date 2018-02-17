#include<iostream.h>
#include<conio.h>

int max,min;
void rmaxmin(int *a,int n,int i)
{
if(i<n)
{
  if(a[i]<a[i+1])
   {
     if(a[i]<a[min])      min=i;
     if(a[i+1]>a[max])     max=i+1;
     }
     if(a[i+1]<a[i])
     {
	  if(a[i+1]<a[min])     min=i+1;
	  if(a[i]>a[max])       max=i;
     }
     i+=2;
    rmaxmin(a,n,i);
     }
     return;
  }
  void main()
  {
  int *a,i,n;
  clrscr();
  cout<<" enter the no of elements"<<endl;
  cin>>n;
  a=new int [n];
  cout<<endl<<"enter the elements";
  for( i=0;i<n;i++)
  cin>>a[i] ;
  if(n==0)
  cout<<"no elements entered \n";
  else if(n==1)
  cout<<"max element is"<<a[max]<<"min element is"<<a[0];
  else
  {
  int s;
     if(n%2)
     {
     min=0;
     max=0;
     s=1;
     }
     else
     {
       if(a[0]>a[1])
       {
       min=1;
       max=0;
       }
      else
      {
      min=0;
      max=1;
      }
	 s=2;
    }
	   rmaxmin(a,n,s);
	   cout<<"max element is"<<a[max]<<endl<<"min element is"<<a[min];
 }
 getch();
 }



