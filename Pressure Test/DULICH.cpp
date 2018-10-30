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
typedef pair<ll,ll> pll;
ll n,m,a,b,k,g,dis[1005],mister[1005],u,v,d,cur=1,adj[1005][1005]={0};
map<pll,pll> unavailable;
bool vis[1005]={0};
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>a>>b>>k>>g;
    adj.resize(n+1);
    up(i,1,g) cin>>mister[i];
    up(i,1,m){
        cin>>u>>v>>d;
        adj[u][v]=d;
        adj[v][u]=d;
    }
    up(i,1,g-1){
        unavailable[{mister[i],mister[i+1]}]
    }
    return 0;
}
