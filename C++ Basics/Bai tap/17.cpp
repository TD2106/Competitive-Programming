#include <iostream>
using namespace std;
int  main ()
{
	int n,s=0,i,a;
	cout <<"Nhap n ";
	cin >>n;
	a=0;
	while (n>=1)
	{
		i=n%10;
		s=s+i;
		n=n/10;
		a++;
	}
	cout<<"Tong cua cac chu so la "<<s<<" va so cac con so la "<<a;
	return 0;
}
