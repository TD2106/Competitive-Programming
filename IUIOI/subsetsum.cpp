#include <iostream>
#include <cstdlib>
using namespace std;
int main ()
{
	bool **dp;
	int T,N,arr[101],sum;
	cin>>T;
	while(T--)
	{
		sum=0;
		cin>>N;
		for(int i=1;i<=N;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
		}
		if(sum%2)
		cout<<"NO\n";
		else
		{
			sum/=2;
			dp=(bool**)malloc((N+1)*sizeof(bool*));
			for(int i=0;i<=N;i++)
			dp[i]=(bool*)malloc((sum+1)*sizeof(bool));
			for(int i=0;i<=N;i++)
			dp[i][0]=1;
			for(int i=1;i<=sum;i++)
			dp[0][i]=0;
			for(int i=1;i<=N;i++)
			{
				for(int j=1;j<=sum;j++)
				{
					if(dp[i-1][j]==1)
					dp[i][j]=1;
					else
					{
						if(arr[i]>j)
						dp[i][j]=dp[i-1][j];
						else
						{
							dp[i][j]=dp[i-1][j-arr[i]];
						}
					}
				}
			}
			if(dp[N][sum])
			cout<<"YES\n";
			else
			cout<<"NO\n";
		}
	}
	return 0;
}
