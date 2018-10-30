#include <iostream>
using namespace std;
int main ()
{
	long long tc,n,k,ans;
	cin>>tc;
	while(tc--)
	{
		ans=1;
		cin>>n>>k;
		ans=1;
		while(n--)
		{
			ans*=k;
			k--;
			ans%=1000000007;
		}
		cout<<ans<<endl;
	}
}
