#include <iostream>
#include <cmath>
using namespace std;
int binary(int n,int i)
{
	int s;
	if(n==0)
	return 0;
	else
	return s=pow(10,i)*(n%2)+binary(n/2,i+1);
}

int dem(int n)
{
	int i=0;
	while (n!=0)
	{
		i++;
		n=n/10;
	}
	return i;
	
}
int dao(int n,int dem)
{
	int s=0;
	for (int i=1;i<=dem;i++)
	{
		s=s+(n%10)*pow(10,dem-i);
		n=n/10;
	}
	return s;
}

int main ()
{
	int n;
	cout<<"Nhap m ";
	cin>>n;
	cout<<"B(m)="<<dao(binary(n,0),dem(binary(n,0)));
}
