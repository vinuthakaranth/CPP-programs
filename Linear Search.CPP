#include<iostream.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<dos.h>

int lsearch(int a[],int n,int key)
  {
   if(n==0)
    return -1;
  if(key==a[n-1])
    return  n-1;
   return(lsearch( a, n-1,key));
   }
 void main()
 {
 int a[10],n,i,key;
 clrscr();
 clock_t strt,end;
 cout<<endl<<"enter the number of element";
  cin>>n;
//  n=3000;
cout<<endl<<"enter the elements:";
 for(i=0;i<n;i++)
  cin>>a[i];
 //  a[i]=rand();
 //  key=a[20];

  cout<<"Enter the key element\n";
  cin>>key;
  strt=clock();
  int pos=lsearch(a,n,key);
  delay(2000);
  end=clock();

   cout<<"the element is found in "<<pos+1<<"position\n";

  cout<<endl<<"time taken to search the element";
  cout<<(end-strt)/CLK_TCK;
  getch();
  }


