#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	unsigned long long t,sum=3,i=1,rs;
	cin>>t;
	while(t>sum)
	{
		i*=2;
		sum+=3*i;
	}
	sum-=t;
	rs=1+sum;
	cout<<rs;
}
