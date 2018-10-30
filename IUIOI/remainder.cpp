#include <iostream>
using namespace std;
unsigned long long max(unsigned long long a, unsigned long long b)
{
	if(a>b)
	return a;
	else
	return b;
}
unsigned long long min(unsigned long long a, unsigned long long b)
{
	if(a<b)
	return a;
	else
	return b;
}
unsigned long long russian(unsigned long long base,unsigned long long temp, unsigned long long mod)
{
	unsigned long long result=0,one=1;
	while(temp)
	{
		if(temp&one)
		{
			result+=base%mod;
			result%=mod;
		}
		base*=2;
		base%=mod;
		temp/=2;
	}
	return result;
}
unsigned long long power(unsigned long long base,unsigned long long pow, unsigned long long mod)
{
	unsigned long long result=1;
	if(pow==0)
	return 1;
	else
	{
		for(int i=1;i<=pow;i++)
		result=russian(max(result,base),min(result,base),mod);
	}
	return result;
}
int main ()
{
	unsigned long long base,mod,pow;
	cin>>base>>pow>>mod;
	cout<<power(base,pow,mod);
	return 0;
}
