#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main ()
{
	int mark[500100]={0};
	int n,k,count=0,check;
	cin>>n>>k;
	if(k<=n)
	count = k;
	for(int i=2;i<=sqrt(n);i++)
	{	
		if(mark[i]==0)
		{
			for(int j=2*i;j<=n;j+=i)
			if(j<=n)
			mark[j]=1;
		}
	}
	int a;
	if(k<=n)
	a=k+1;
	else
	a=1;
	for(int i=a;i<=n;i++)
	{
		
		check=1;
		for(int j=k+1;j<=i;j++)
		{
			if(mark[j]==0)
			{
				if(i%j==0)
				{
					check=0;
					break;
				}
			}
		}
		if(check)
		count ++;
	}
	cout<<count;
	return 0;
}
