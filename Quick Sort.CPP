			      /*quick sort*/
#include<iostream.h>
#include<conio.h>
void quick(int *a,int low,int high)
{
int i=low,j=high+1,key=a[low];
if(low>=high)
return;
while(1)
{
   do{   i++;   }while(a[i]<key);
   do{   j--;    }while(a[j]>key);
   if(i>j)
   break;
   int temp=a[i];
   a[i]=a[j];
   a[j]=temp;
 }
 a[low]=a[j];
 a[j]=key;
 quick(a,low,j-1);
 quick(a,j+1,high);
}
 void main()
 {
 int a[10],n;
  clrscr();
  cout <<endl<<"enter the size"<<endl;
  cin>>n;
  cout <<"enter the elements"<<endl    ;
  for(int i=0;i<n;i++)
  cin>>a[i];
  quick(a,0,n-1);
  cout<<endl<<  "sorted array" <<endl  ;
  for(i=0;i<n;i++)
  cout<<" \t  "<<a[i];
  getch();
  }

