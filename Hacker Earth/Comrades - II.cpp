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
bool vis[100005];
vector<vll> adj;
ll n,Ti=0,t,dis[100005],tc,root;
void dfs(ll st){
    vis[st]=1;
    if(st!=root) dis[st]=++t;
    for(int i=0;i<adj[st].size();i++){
        if(!vis[adj[st][i]]) dfs(adj[st][i]);
    }
    --t;
}
int main(){
    cin>>tc;
    while(tc--){
        adj.clear();
        reset(vis);
        reset(dis);
        cin>>n;
        adj.resize(n+1);
        for(int i=1;i<=n;i++){
            cin>>t;
            if(t==0) root=i;
            else{
                adj[i].pb(t);
                adj[t].pb(i);
            }
        }
        t=Ti=0;
        dfs(root);
        for(int i=1;i<=n;i++) Ti+=dis[i];
        cout<<Ti<<" "<<n*(n-1)/2-Ti<<endl;
    }
    return 0;
}



