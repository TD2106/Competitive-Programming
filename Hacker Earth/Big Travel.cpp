#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#define mod 1000000007
using namespace std;
vector<long long> x,y;
unsigned long long sumx[200010]={0},sumy[200010]={0},n,temp,ans=0;
int main ()
{
	// general idea this is just sorting and dp
	// find the diff between the sum of the next number in 
	// the consecutive sequence
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		x.push_back(temp);
		cin>>temp;
		y.push_back(temp);
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	for(int i=1;i<n;i++)
	{
		sumx[0]+=(x[i]-x[0]);
		sumy[0]+=(y[i]-y[0]);
	}
	for(int i=1;i<n;i++)
	{
		sumx[i]=sumx[i-1]-(n-i-1)*(x[i]-x[i-1])+(i-1)*(x[i]-x[i-1]);
		sumy[i]=sumy[i-1]-(n-i-1)*(y[i]-y[i-1])+(i-1)*(y[i]-y[i-1]);
	}
	for(int i=0;i<n;i++)
	{
		ans+=sumx[i]%mod+sumy[i]%mod;
		ans%=mod;	
	}
	cout<<(ans*500000004)%mod<<endl;
	// multiply by 500000004 because of modulo division arithmetic 
	return 0;
}
