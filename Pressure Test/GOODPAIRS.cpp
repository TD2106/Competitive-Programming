#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
typedef long long int ll;
ll n,a[30]={0},Ti=0;
int main(){
	ios_base::sync_with_stdio(0);
	fr("GOODPAIRS.INP");
	fw("GOODPAIRS.OUT");
	cin>>n;
	up(i,1,n) cin>>a[i];
	up(i,1,n) Ti+=min(a[i],a[i+1]);
	cout<<Ti<<endl;
	return 0;
}
