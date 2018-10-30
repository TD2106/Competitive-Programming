#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100000;
const int oo = 1000000000;
int n,q,k,b[maxn+1],a[maxn+1],x[maxn+1],y[maxn+1];
int l[maxn*100],r[maxn*100],cnt[maxn*100],update[maxn*100],vt[maxn+1];
int dau,cuoi;
void enter()
{
	cin >> n >> q >> k;
	k++;
	dau=oo,cuoi=-oo;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		b[i]=a[i];
		dau=min(dau,a[i]);
		cuoi=max(cuoi,a[i]);
	}
	sort(b+1,b+1+n);
	for (int i=1; i<=q; i++)
	{
		cin >> x[i] >> y[i];
		x[i]++;
		y[i]++;
	}
}
void initIT(int i,int x,int y,int k)
{
	l[i]=x;
	r[i]=y;
	update[i]=0;
	if (x==y)
	{
		if (a[x]>=k) cnt[i]=1;
		else cnt[i]=0;
		vt[x]=i;
	}
	else
	{
		int mid=(x+y)/2;
		initIT(i*2,x,mid,k);
		initIT(i*2+1,mid+1,y,k);
		cnt[i]=cnt[i*2]+cnt[i*2+1];
	}
	//cout << "initIT " << i << ' ' << x << ' ' << y << ' ' << cnt[i] << '\n';
}
void updateNode(int i)
{
	if (update[i]==1)
	{
		cnt[i]=0;
		if (l[i]!=r[i])
		{
			update[i*2]=1;
			update[i*2+1]=1;
		}
	}
	else
	if (update[i]==2)
	{
		cnt[i]=r[i]-l[i]+1;
		if (l[i]!=r[i])
		{
			update[i*2]=2;
			update[i*2+1]=2;
		}
	}
	update[i]=0; // don't need update
}
int cntIT(int i,int x,int y)
{
	if (y<x) return 0;
	updateNode(i);
	int res;
	if (x<=l[i] and r[i]<=y) res=cnt[i];
	else
	if (r[i]<x or l[i]>y) res=0;
	else
		if (r[i]!=l[i])
		res=cntIT(i*2,x,y)+cntIT(i*2+1,x,y);
	//cout << i << ' ' << l[i] << ' ' << r[i] << ' ' << cnt[i] << ' ' << res << '\n';
	return res;
}
void update1(int i,int x,int y) // clear [x;y]
{
	if (y<x) return;
	updateNode(i); // may be node_i hasn't been updated.
	if (x<=l[i] and r[i]<=y)
	{
		update[i]=1;
		updateNode(i);
		//update[i]=0;
	}
	else
	if (r[i]<x or l[i]>y) return;
	else
	if (r[i]!=l[i])
	{
		update1(i*2,x,y);
		update1(i*2+1,x,y);
		cnt[i]=cnt[i*2]+cnt[i*2+1];
	}	
}
void update2(int i,int x,int y) // set [x;y]
{
	if (y<x) return;
	updateNode(i); // may be node_i hasn't been updated.
	if (x<=l[i] and r[i]<=y)
	{
		update[i]=2;
		updateNode(i);
		//update[i]=0;
	}
	else
	if (r[i]<x or l[i]>y) return;
	else
	if (r[i]!=l[i])
	{
		update2(i*2,x,y);
		update2(i*2+1,x,y);
		cnt[i]=cnt[i*2]+cnt[i*2+1];
	}
}
void duyet(int i) // print info
{
	if (l[i]!=r[i]) duyet(i*2);
	cout << i << ' ' << l[i] << ' ' << r[i] << ' ' << a[l[i]] << ' ' << cnt[i] << ' ' << update[i] << '\n';
	if (l[i]!=r[i]) duyet(i*2+1);
}
int get(int x)
{
	return cntIT(1,x,x);
}
bool check(int val)
{
	initIT(1,1,n,val);
	for (int i=1; i<=q; i++)
	{
		int p=cntIT(1,x[i],y[i]),pp=y[i]-x[i]+1-p;
		//cout << p << '\n';
		update2(1,y[i]-p+1,y[i]);
		//cout << "update2" << ' ' << y[i]-p+1 << ' ' << y[i] << '\n';
		//duyet(1);
		//cout << '\n';
		//cout << "update1" << ' ' << x[i] << ' ' << x[i]+pp-1 << '\n';
		update1(1,x[i],x[i]+pp-1);
		//duyet(1);
		//cout << '\n';
	}
	//duyet(1);
	return get(k);
}
void solve()
{
	int dau=1,cuoi=n;
	do
	{
		int giua=(dau+cuoi)/2;
		if (check(b[giua])) dau=giua+1;
		else cuoi=giua-1;
	}
	while (dau<=cuoi);
	cout << b[cuoi];
}
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("sortsubseg.inp","r",stdin);
	//freopen("sortsubseg.out","w",stdout);
	enter();
	solve();
	return 0;

}