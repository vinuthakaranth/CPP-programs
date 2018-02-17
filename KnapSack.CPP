#include<iostream.h>
#include<conio.h>

float w[10],p[10],pwd[10],n,c,x[10];
int index[10];

void sort()
{
  for(int i=0;i<n;i++)
   index[i]=i;
    for(i=1;i<n;i++)
    for(int j=0;j<n-i;j++)
	if(pwd[j]<=pwd[j+1])
	{
	float temp=pwd[j];
	pwd[j]=pwd[j+1];
	pwd[j+1]=temp;

	int tempi=index[j];
	index[j]=index[j+1];
	index[j+1]=tempi;
	}
}



void load()
  {
     sort();
     int c1=0;
     for(int i=0;i<n;i++)
     {
     c1=c1+w[index[i]];
     x[index[i]]=1;
     if(c1>c)
       {
	  x[index[i]]=0;
	  c1-=w[index[i]];
	}
      }
     cout<<"solution:"<<endl;
     float profit=0;
      for( i=0;i<n;i++)
      {
	if(x[i]!=0)
	 profit+=p[i];
	cout<<" "<<x[i];
       }
    cout<<endl<<"Profit="<<profit<<endl;
 }


void main()
{
 clrscr();
 cout<<"enter no of articles"<<endl;
  cin>>n;
 cout<<"enter capacity"<<endl;
  cin>>c;
 cout<<"enter weights snd profits"<<endl;
 for(int i=0;i<n;i++)
  cin>>w[i]>>p[i];
 for(i=0;i<n;i++)
  pwd[i]=p[i]/w[i];
 load ();
 getch();
}

