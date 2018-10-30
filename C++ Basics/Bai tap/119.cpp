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

int check(int n,int i)
{
	int a,s=0;
	int k=0;
	for(int j=1;j<=i;j++)
	{
		a=n%10;
		n=n/10;
		s=s+a*pow(10,k);
		k++;
	}
	return s;
}

int main()
{
	int n,a=1;
	cout<<"Nhap vao so n: ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k=i*i;
		if(check(k,dem(i))==i)
		{
			a=0;
			cout <<"So "<<i<<" thoa de bai"<<endl;
		}
	}
	if(a)
	cout<<"Ko co so thoa de bai"<<endl;
}
