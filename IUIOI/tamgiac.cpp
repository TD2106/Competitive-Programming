#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;
int main ()
{
	bitset<2000001> prime;
	prime[1]=1;
	for(int i=2;i<=sqrt(2000000);i++)
	{
		if(!prime[i])
		{
			for(int j=i*i;j<=2000000;j+=i)
			prime[j]=1;
		}
	}
	long long sum;
	int testcase,n;
	cin>>testcase;
	while(testcase--)
	{
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(((prime[i+k]&prime[i+j]&prime[j+k])==1)||((prime[i+j]|prime[i+k]|prime[j+k])==0))
					{
						sum++;
					}
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
