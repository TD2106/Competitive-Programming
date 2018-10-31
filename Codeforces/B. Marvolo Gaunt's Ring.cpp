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
#define M 100005
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
ll n,p,q,r,t,Ti=-5e18,dp[3][100005]={0};
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>p>>q>>r;
    up(i,1,n){
        cin>>t;
        dp[0][i]=p*t;
        dp[1][i]=q*t;
        dp[2][i]=r*t;
    }
    up(i,2,n) dp[0][i]=max(dp[0][i-1],dp[0][i]);
    down(i,n-1,1) dp[2][i]=max(dp[2][i],dp[2][i+1]);
    up(i,1,n) Ti=max(Ti,dp[0][i]+dp[1][i]+dp[2][i]);
    cout<<Ti<<endl;
    return 0;
}
