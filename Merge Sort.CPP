			   /* merge sort */
#include<iostream.h>
#include<conio.h>
void mergesort(int *a,int low,int high,int mid)
{
 int i,j,k,c[20];
 i=low;
 j=mid+1;
 k=low;
    while(i<=mid && j<=high)
   {
if(a[i]<a[j])
c[k++]=a[i++];
else
c[k++]=a[j++];
    }
       while(i<=mid)
      c[k++]=a[i++];
while(j<= high)
c[k++]=a[j++];

for( i=low;i<k;i++)
a[i]=c[i];
}

void merge(int *a,int low ,int high)
{
int mid=(low+high)/2;
if(low<high)
{
merge(a,low,mid);
merge(a,mid+1,high);
mergesort(a,low,high,mid);
}
}

void main()
{
int n;
cout<<"enter size"<<endl;
cin>>n;
cout <<"enter the elements"<<endl;
int *a=new int[n];
for(int i=0;i<n;i++)
cin>>a[i];
merge(a,0,n-1);
for(i=0;i<n;i++ )
cout<<"\t"<< a[i];
getch();
}