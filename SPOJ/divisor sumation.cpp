#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	long long t,n;
	cin>>t;
	while(t--)
	{
		long long sum=1;
		cin>>n;
		if(n==1)
		{
			cout<<"0\n";
			continue;
		}
		for(int i=2;i<=sqrt(n);i++)
		if(n%i==0)
		if(n%i!=i)
		sum+=i+(n/i);
		else
		sum+=i;
		cout<<sum<<"\n";
	}
	return 0;
}
