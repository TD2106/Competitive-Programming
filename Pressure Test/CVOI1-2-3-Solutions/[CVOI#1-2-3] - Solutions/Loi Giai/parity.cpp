#include <iostream>
#include <cstdio>
#include <map>
#define X first
#define Y second
using namespace std;
const int maxn = 1000000000;
const int maxm = 5000;
int n,m;
map<int,int> id;
int cha[maxm*4+1];
int findcha(int x)
{
	if (cha[x]==x) return x;
	else return cha[x]=findcha(cha[x]);
}
void uni(int x,int y)
{
	cha[findcha(x)]=findcha(y);
}
int main()
{
	ios_base::sync_with_stdio(0);
	freopen("PARITY.INP","r",stdin);
	freopen("PARITY.OUT","w",stdout);
	while (cin >> n >> m and n!=-1)
	{
		int x,y;
		string s;
		bool f=false;
		id.clear();
		for (int i=1; i<=4*m; i++)
			cha[i]=i;
		for (int i=1; i<=m; i++)
		{
			cin >> x >> y >> s;
			x--;
			if (!id.count(x)) id[x]=id.size();
			if (!id.count(y)) id[y]=id.size();
			if (!id.count(x+n+1)) id[x+n+1]=id.size();
			if (!id.count(y+n+1)) id[y+n+1]=id.size();
			int idx=id[x],idy=id[y],idxn=id[x+n+1],idyn=id[y+n+1];
			if (s=="even")
			{
				uni(idx,idy);
				uni(idxn,idyn);
			}
			else
			{
				uni(idx,idyn);
				uni(idxn,idy);
			}
			if ((findcha(idx)==findcha(idxn) or findcha(idy)==findcha(idyn)))
			{
				if (!f) cout << i-1 << '\n';
				f=true;
			}
		}
		if (!f)
			cout << m << '\n';
	}
	return 0;
}
