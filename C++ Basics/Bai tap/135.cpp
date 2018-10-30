#include <iostream>
using namespace std;
int BCNN(int a,int b)
{
	int m=a,n=b;
	while(a*b!=0)
	{
		if(a>=b)
		a=a%b;
		else
		b=b%a;
	}
	return (m*n)/(a+b);
}

int check(int n)
{
	int a=1,b=0,c=0;
	while(n>0)
	{
		if(n%10!=0&&n%10!=7)
		{
			a=0;
			break;
		}
		if(n%10==7)
		b=1;
		if(n%10==0)
		c=1;
		n=n/10;
	}
	if(a*b*c)
	return 1;
	else
	return 0;
}

int main ()
{
	int n,TEST;
	cout<<"Nhap so n ";
	cin>>n;
	int i=1,a=0;
	while(a==0)
	{
		TEST=BCNN(n,7)*i;
		if(check(TEST))
		a=1;
		i++;
	}
	cout<<"Ket qua la "<<TEST<<endl;
	return 0;
	
	
}
