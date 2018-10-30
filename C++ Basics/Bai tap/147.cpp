#include <iostream>
#include <cmath>
using namespace std;

int kq(int n)
{
	float a=log(n)/log(2);
	int b=int(a);
	if(n==pow(2,b)) return 1;
	else
	{
		if(n%2==0)
		return kq(n/2);
		else
		return kq(n/2+1)+kq(n/2);
	}
}
int main ()
{
	int n;
	cout<<"Nhap n ";
	cin>>n;
	cout<<kq(n);
	return 0;
}
