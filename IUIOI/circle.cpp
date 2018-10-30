#include <iostream>
using namespace std;
int main ()
{
	long long n;
	cin>>n;
	if(n==0)
	cout<<"1";
	else
	{
		long long tong=0;
		tong=n*(n-1)+2;
		cout<<tong;
	}
}
