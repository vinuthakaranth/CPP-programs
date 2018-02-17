#include<iostream.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<dos.h>

int bsearch(int a[],int low,int high,int key)
{
   int mid=(low+high)/2;
   if(key==a[mid])
   return mid;
   if(key<mid)
   return(bsearch(a,low,mid-1,key));
   return(bsearch(a,mid+1,high,key));
}


void main()
 {
 int a[10],n,i,key,low=0,high=n-1;
 clrscr();
 clock_t strt,end;
cout<<endl<<"enter the number of element";
 cin>>n;
//  n=3000;
cout<<endl<<"enter the elements:";
 for(i=0;i<n;i++)
 cin>>a[i];
//   a[i]=rand();
//   key=a[20];
cout<<"Enter the key element";
cin>>key;
  strt=clock();
  int pos=bsearch(a,low,high,key);
  delay(2000);
  end=clock();

  if(pos!=-1)
  cout<<"the element is found in "<<pos+1<<"position";
  else
  cout<<"not found";
  cout<<endl<<"time taken to search the element";
  cout<<(end-strt)/CLK_TCK;
  getch();
  }


