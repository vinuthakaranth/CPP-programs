#include<iostream.h>
#include<conio.h>
#include<math.h>

int x[10],n;

void display();
int place(int,int);

void nqueen(int k,int n)
{
 for(int i=1;i<=n;i++)
 {
   if(place(k,i))
   {
	x[k]=i;
	if(k==n)
	{
		 display();
		 return;
	}
	nqueen(k+1,n);
   }
 }
}

     int place(int k,int i)
     {
     for(int j=1;j<=k-1;j++)
     {
     if(x[j]==i||abs(x[j]-i)==abs(j-k))
     return 0;
     }
     return 1;
     }

     void display()
     {
     cout<<"\nROW  COLUMN\n";
     for(int i=1;i<=n;i++)
     cout<<"\n"<<i<<"\t"<<x[i];
     getch();
     }

     void main()
     {
     clrscr();
     cout<<"\n Enter the number of queens";
     cin>>n;
     cout<<"\nArrangement:";
     nqueen(1,n);
     getch();
     }

