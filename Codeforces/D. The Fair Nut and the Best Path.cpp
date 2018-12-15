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
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

ll n, w[300005], u, v, c, ans = 0, dp[300005] = {0};
vector<vpii> adj;

void dfs(int x, int p){
    dp[x] = w[x];
    ll max1 = 0, max2 = 0;
    for(pii node : adj[x]){
        if(node.fi == p){
            continue;
        }
        dfs(node.fi, x);
        dp[x] = max(dp[x], dp[node.fi] - node.se + w[x]);
        if(max1 < dp[node.fi] - node.se){
            max2 = max1;
            max1 = dp[node.fi] - node.se;
        } else{
            max2 = max(dp[node.fi] - node.se, max2);
        }
    }
    ans = max(dp[x], ans);
    ans = max(max1 + max2 + w[x], ans);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    adj.resize(n + 1);
    up(i, 1, n) cin >> w[i];
    up(i, 1, n - 1){
        cin >> u >> v >> c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
