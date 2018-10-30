#include <iostream>
using namespace std;
int main ()
{
	int m,n,q,x,y,u,v;
	cin>>m>>n>>q;
	long long temp,sum[m+1][n+1];
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		sum[i][j]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>temp;
			sum[i][j]=temp+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	}
	while(q--)
	{
		cin>>x>>y>>u>>v;
		cout<<sum[u][v]+sum[x-1][y-1]-sum[x-1][v]-sum[u][y-1]<<"\n";
	}
	return 0;
}
