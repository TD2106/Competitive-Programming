#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
const ll maxn = 64;
const ll maxk = 100;
ll n,k;
ll dp[maxn+1][maxn+1][maxk+1];
ll caldp(ll x,ll y,ll z)
{
	if (dp[x][y][z]==-1)
	{
		if (x==0 and y==0 and z==0) dp[x][y][z]=1;
		else
		if (x==0 and y==0 and z!=0) dp[x][y][z]=0;
		else
		{
			dp[x][y][z]=0;
			if (x>0) dp[x][y][z]+=caldp(x-1,y,(z<<1)%k);
			if (y>0) dp[x][y][z]+=caldp(x,y-1,((z<<1)+1)%k);
		}
		//cout << x << ' ' << y << ' ' << z << ' ' << dp[x][y][z] << '\n';
	}
	return dp[x][y][z];
}
void solve()
{
	cin >> n >> k;
	if (n&1 or k==0) cout << 0 << '\n';
	else
	{
		for (int i=0; i<=n>>1; i++)
			for (int j=0; j<=(n>>1)-1; j++)
				for (int z=0; z<k; z++)
					dp[i][j][z]=-1;
		cout << caldp(n>>1,(n>>1)-1,1%k) << '\n';
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("010101.inp","r",stdin);
	//freopen("010101.out","w",stdout);
	solve();
	return 0;
}