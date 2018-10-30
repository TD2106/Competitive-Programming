#include <iostream>
#include <math.h>
using namespace std;
int dem(int n)
{
	int i=0;
	while(n!=0)
	{
		n=n/10;
		i++;
	}
	return i;
}

int daonguoc(int n,int i)
{
	int s=0;
	i=i-1;
	int a;
	for(int j=i;j>=0;j--)
	{
		a=n%10;
		n=n/10;
		s=s+a*pow(10,j);
	}
	return s;
}

int check(int n,int s)
{
	int a=0;
	if(n==s)
	{
		a=1;
	}
	return a;
}

int main()
{
	for(int j=0;j<100;j++)
	{
		int n=j*j;
		if(check(n,daonguoc(n,dem(n))))
	    cout<<"So binh phuong cua "<<j<<" la so palindrom"<<endl;
	    if(check(j,daonguoc(j,dem(j))))
	    {
	    	if(check(n,daonguoc(n,dem(n))))
	    	cout<<j<<" vua la so palindrom va binh phuong cua no cung la so palindrom"<<endl;
		}
	}
	return 0;
}
