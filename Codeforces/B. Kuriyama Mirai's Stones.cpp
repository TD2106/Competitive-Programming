#include <bits/stdc++.h>
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define reset(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define pb push_back
#define ins insert
#define mp make_pair
#define fi first
#define se second
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
ll n,v[100005],u[100005],dp[2][100005]={0},q,l,r,t;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        dp[0][i]=dp[0][i-1]+v[i];
        u[i]=v[i];
    }
    sort(u+1,u+1+n);
    for(int i=1;i<=n;i++) dp[1][i]=dp[1][i-1]+u[i];
    cin>>q;
    while(q--){
        cin>>t>>l>>r;
        cout<<dp[t-1][r]-dp[t-1][l-1]<<endl;
    }
    return 0;
}



