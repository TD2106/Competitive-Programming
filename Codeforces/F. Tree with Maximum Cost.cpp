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
#define MAX 200005
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
int n, w[MAX] = {0}, u, v;
ll valueInSubTree[MAX] = {0}, dp[MAX] = {0}, total = 0, ans = 0, currentCost = 0;
vector<vi> adj;
void dfs(int x, int p, int dist){
    for(int i : adj[x]){
        if(i == p) continue;
        dfs(i, x, dist + 1);
        valueInSubTree[x] += valueInSubTree[i];
    }
    valueInSubTree[x] += w[x];
    currentCost += (ll)dist * (ll)w[x];
}
void findAns(int x, int p){
    for(int i : adj[x]){
        if(i == p) continue;
        dp[i] = dp[x] - 2 * valueInSubTree[i] + total;
        findAns(i, x);
    }
    ans = max(ans, dp[x]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    adj.resize(n + 1);
    up(i, 1, n){
        cin >> w[i];
        total += w[i];
    }
    up(i, 1, n - 1){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0, 0);
    dp[1] = currentCost;
    findAns(1, 0);
    cout << ans << endl;
    return 0;
}
