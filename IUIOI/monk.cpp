#include <iostream>
#define mod 1000000007	
using namespace std;
long long gcd(long long a,long long b)
{
	if(a*b==0)
	return a+b;
	else
	return gcd(b,a%b);
}
int main ()
{
	long long n,arr[51]={0},g,f=1,ans=1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	g=gcd(arr[0],arr[1]);
	for(int i=2;i<n;i++)
	{
		g=gcd(g,arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		f*=arr[i];
		f%=mod;
	}
	for(int i=0;i<g;i++)
	{
		ans=ans*f;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
