#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <map>
using namespace std;
int main ()
{
	bitset<5000001> check;
	bitset<5000001> mark;
	int n,k,count2=0;
	cin>>n>>k;
	if(k>=n)
	{
		cout<<n;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{	
		if(mark[i]==0&&i<=k)
		{
			for(int j=2*i;j<=n;j+=i)
			if(j<=n)
			mark[j]=1;
		}
		else if(mark[i]==0&&i>k)
		{
			count2++;
			for(int j=2*i;j<=n;j+=i)
			{
				if(check[j]==0)
				count2++;
				check[j]=1;
			}
		}
	}
	cout<<n-count2;
}
