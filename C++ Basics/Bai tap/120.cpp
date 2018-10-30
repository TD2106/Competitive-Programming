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
	for(int j=1;j<=i;j++)
	{
		a=n%10;
		n=n/10;
		s=s+pow(a,i);
	}
	return s;
}
int main()
{
	int n;
	cout<<"Nhap vao so n: ";
	cin>>n;
	if(check(n,dem(n))==n)
	cout<<"So n thoa";
	else
	cout<<"So n ko thoa";
}
