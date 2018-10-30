#include <iostream>
#include <cmath>
#define mod 1000000007
using namespace std;
int main ()
{
	ios::sync_with_stdio(false);
	long long arr[64];
	for(int i=0;i<64;i++)
	{
		arr[i]=(long long)pow(2,i);
	}
	long long t,n,lim,sum;
	cin>>t;
	while(t--)
	{
		cin>>n;
		lim=(long long)ceil(log(n)/log(2));
		for(int i=1;i<lim;i++)
		{
			for(int j=0;j<i;j++)
			if(arr[i]+arr[j]>n)
			break;
			else
			sum+=arr[i]%mod+arr[j]%mod;
		}
		cout<<sum%mod<<"\n";
	}
	return 0;
}
