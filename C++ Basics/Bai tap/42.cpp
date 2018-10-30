#include <iostream>
using namespace std;
int giaithua(int n)
{
	if(n==0)
	return 1;
	else
	return n*giaithua(n-1);
}
int main ()
{
	int n=-1,m=-1;
	while(n<0||m<0)
	{
		cout<<"Enter n and m >= 0 ";
		cin>>n>>m;
	}
	cout<<(giaithua(n)+giaithua(m))*1.0/giaithua((n+m));
}
