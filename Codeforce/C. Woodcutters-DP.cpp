#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
int x[100005],h[100005],s[100005]={0},l[100005]={0},r[100005]={0},n,Ti;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i]>>h[i];
	x[n+1]=2e9+5;
	x[0]=-2e9-5;
	for(int i=1;i<=n;i++){
        s[i]=max(r[i-1],max(s[i-1],l[i-1]));
        if(x[i]-h[i]>x[i-1]+h[i-1]) l[i]=r[i-1]+1;
        else if(x[i]-h[i]>x[i-1]) l[i]=max(s[i-1]+1,l[i-1]+1);
        else l[i]=-n;
        if(x[i]+h[i]<x[i+1]) r[i]=max(s[i-1]+1,l[i-1]+1);
        else r[i]=-n;
        if(x[i]>x[i-1]+h[i-1]&&x[i]+h[i]<x[i+1]) r[i]=max(r[i],r[i-1]+1);
	}
	Ti=max(max(s[n],l[n]),r[n]);
	cout<<Ti<<endl;
	return 0;
}
