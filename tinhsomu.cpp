#include <iostream>
#include <map>
using namespace std;
map<int,long long> pow;
long long power(int a,int n)
{
	if(n==0)
	return 1;
	if(pow[n])
	{
		return pow[n];
	}
	else
	{
		if(n%2)
		{
			pow[n]=a*power(a,n/2)*power(a,n/2);
			return pow[n];
		}
		else
		{
			pow[n]=power(a,n/2)*power(a,n/2);
			return pow[n];
		}
	}
}
int main ()
{
	int a,n;
	cout<<"Enter a and n ";
	cin>>a>>n;
	cout<<power(a,n);
	return 0;
}
