#include <iostream>
#include <cmath>
using namespace std;
long long a,b,c,d,k,tc;
long long f(long long ans)
{
	long long re=a*ans*ans*ans+b*ans*ans+c*ans+d;
	return re;
}
int main ()
{
	cin>>tc;
	while(tc--)
	{
		cin>>a>>b>>c>>d>>k;
		long long ans=(long long)pow(k*1.0/a,1/3)+1;
		while(f(ans+1)<=k)
		ans++;
		while(f(ans)>k)
		ans--;
		if(ans<0)
		ans=0;
		cout<<ans<<endl;
	}
	return 0;
}
