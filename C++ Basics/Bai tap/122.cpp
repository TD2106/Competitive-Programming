#include <iostream>
#include <math.h>
using namespace std;
int check(int n)
{
	int a,b;
	b=n;
	int i=0;
	while(b!=0)
	{
		b=b/10;
		i++;
	}
	b=n;
	int s=0;
	i=i-1;
	for(int j=i;j>=0;j--)
	{
		a=b%10;
		b=b/10;
		s=s+a*pow(10,j);
	}
	if(s==n)
	return n;
	else
	check(n+s);
}
int main()
{
	int n;
	cout<<"Nhap so n: ";
	cin >>n;
	cout<<"Ket qua cuoi cung la: "<<check(n)<<endl;
	return 0;
}



