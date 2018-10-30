#include <iostream>
using namespace std;
int main ()
{
	long long n;
	cin>>n;
	if(n==3)
	cout<<"0";
	else
	cout<<(n-3)*(n-2)*(n-1)*n/24;
	return 0;
}
