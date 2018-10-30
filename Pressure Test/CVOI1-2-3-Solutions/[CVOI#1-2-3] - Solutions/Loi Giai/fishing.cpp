#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxr = 100;
const int oo = 1000000000;
int r,c,d[maxr+1][maxr+1];
int dp1[maxr+1][maxr+1][maxr*maxr+1],dp2[maxr+1][maxr+1][maxr*maxr*2+1];
int caldp1(int x,int y,int z)
{
	if (dp1[x][y][z]==-1)
	{
		if (z==0) dp1[x][y][z]=0;
		else
		if (z>min(x,y)) dp1[x][y][z]=oo;
		else
		if (x==z and y==z) dp1[x][y][z]=d[x][y]+caldp1(x-1,y-1,z-1);
		else
		{
			dp1[x][y][z]=oo;
			if (x>1) dp1[x][y][z]=min(dp1[x][y][z],caldp1(x-1,y,z));
			if (y>1) dp1[x][y][z]=min(dp1[x][y][z],caldp1(x,y-1,z));
			dp1[x][y][z]=min(dp1[x][y][z],caldp1(x-1,y-1,z-1)+d[x][y]);
		}
	}
	return dp1[x][y][z];
}
int caldp2(int x,int y,int z)
{
	if (dp2[x][y][z]==-1)
	{
		if (z==0) dp2[x][y][z]=0;
		else
		if (z>min(x,y)) dp2[x][y][z]=0;
		else
		if (x==z and y==z) dp2[x][y][z]=d[x][y]+caldp2(x-1,y-1,z-1);
		else
		{
			dp2[x][y][z]=0;
			if (x>1) dp2[x][y][z]=max(dp2[x][y][z],caldp2(x-1,y,z));
			if (y>1) dp2[x][y][z]=max(dp2[x][y][z],caldp2(x,y-1,z));
			dp2[x][y][z]=max(dp2[x][y][z],caldp2(x-1,y-1,z-1)+d[x][y]);
		}
	}
	//cout << x << ' ' << y << ' ' << z << ' ' << dp2[x][y][z] << '\n'; 
	return dp2[x][y][z];
}
void solve()
{
	cin >> r >> c;
	for (int i=1; i<=r; i++)
		for (int j=1; j<=c; j++)
			cin >> d[i][j];
	for (int i=0; i<=r; i++)
		for (int j=0; j<=c; j++)
			for (int z=0; z<=min(r,c); z++)
			{
				dp1[i][j][z]=-1;
				dp2[i][j][z]=-1;
			}
	int res=0;
	for (int i=1; i<=min(r,c)/2; i++)
	{
		res=max(res,caldp2(r,c,i)-caldp1(r,c,i*2));
		//cout << i << ' ' << caldp2(r,c,i) << ' ' << caldp1(r,c,i*2) << '\n';
	}
	//cout << caldp2(r,c,1) << ' ' << caldp1(r,c,2) << '\n';
	cout << res << '\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	freopen("fishing.inp","r",stdin);
	freopen("fishing.out","w",stdout);
	solve();
	return 0;
}