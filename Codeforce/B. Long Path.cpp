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
ll dp[1005]={0},n,p[1005],mod=1e9+7,Ti=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	up(i,1,n) cin>>p[i];
	up(i,1,n){
	    dp[i]=2;
        up(j,p[i],i-1){
            dp[i]+=dp[j];
            dp[i]%=mod;
        }
        Ti=(Ti+dp[i])%mod;
	}
	cout<<Ti<<endl;
	return 0;
}