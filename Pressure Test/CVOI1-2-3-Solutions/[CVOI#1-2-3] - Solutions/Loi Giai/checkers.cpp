#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define ii pair<int,int>
#define X first
#define Y second
using namespace std;
const int maxn = 26;
int n,deg[maxn+1][maxn+1];
char a[maxn+1][maxn+1];
bool visit[maxn+1][maxn+1],visit2[maxn+1][maxn+1],b[maxn+1][maxn+1][maxn+1][maxn+1];
vector<ii> V;
void addEdge(int x1,int y1,int x2,int y2)
{
	if (!b[x1][y1][x2][y2])
	{
		//cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
		deg[x1][y1]++;
		deg[x2][y2]++;
		b[x1][y1][x2][y2]=true;
		b[x2][y2][x1][y1]=true;
	}
}
void dfs(int x,int y)
{
	visit[x][y]=true;
	if (x+2<=n and y+2<=n and a[x+1][y+1]=='W' and a[x+2][y+2]=='_')
	{
		visit2[x+1][y+1]=true;
		addEdge(x,y,x+2,y+2);
		if (!visit[x+2][y+2]) dfs(x+2,y+2);
	}
	if (x+2<=n and y-2>=1 and a[x+1][y-1]=='W' and a[x+2][y-2]=='_')
	{
		visit2[x+1][y-1]=true;
		addEdge(x,y,x+2,y-2);
		if (!visit[x+2][y-2]) dfs(x+2,y-2);
	}
	if (x-2>=1 and y+2<=n and a[x-1][y+1]=='W' and a[x-2][y+2]=='_')
	{
		visit2[x-1][y+1]=true;
		addEdge(x,y,x-2,y+2);
		if (!visit[x-2][y+2]) dfs(x-2,y+2);
	}
	if (x-2>=1 and y-2>=1 and a[x-1][y-1]=='W' and a[x-2][y-2]=='_')
	{
		visit2[x-1][y-1]=true;
		addEdge(x,y,x-2,y-2);
		if (!visit[x-2][y-2]) dfs(x-2,y-2);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	freopen("CHECKERS.INP","r",stdin);
	freopen("CHECKERS.OUT","w",stdout);
	cin >> n;
	V.clear();
	int dem1=0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		{
			cin >> a[i][j];
			if (a[i][j]=='B') V.push_back(ii(i,j));
			if (a[i][j]=='W') dem1++;
		}
	int res=0;
	for (auto it=V.begin(); it!=V.end(); it++)
	{
		memset(deg,0,sizeof(deg));
		memset(visit,false,sizeof(visit));
		memset(visit2,false,sizeof(visit2));
		memset(b,false,sizeof(b));
		dfs((*it).X,(*it).Y);
		int dl=0,dem2=0;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				{
					if (visit2[i][j]) dem2++;
					if (deg[i][j]%2==1) dl++;
				}
		//cout << dem1 << ' ' << dem2 << '\n';
		//cout << dl << '\n';
		if ((dl==0 or (dl==2 and deg[(*it).X][(*it).Y]%2==1)) and dem1==dem2)
			res++;
	}
	cout << res;
	return 0;
}
