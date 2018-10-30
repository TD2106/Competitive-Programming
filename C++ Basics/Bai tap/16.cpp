#include <iostream>
using namespace std;
int  main ()
{
	int n,s=0,i,a;
	cout <<"Nhap n ";
	cin >>n;
	a=n;
	while (n>=1)
	{
		i=n%10;
		s=s+i*i;
		n=n/10;
	}
	if(s==a)
	cout <<"So thoa de bai";
	else
	cout <<"So ko thoa";
	return 0;
}
