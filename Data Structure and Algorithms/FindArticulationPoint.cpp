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
int n,m,level[55]={0},low[55]={0},par[55]={0},u,v;
vector<vi> adj;
bool vis[55]={0};
set<int> Ti;
set<pii> bridge;
void dfsLowLink(int x){
    level[x]=level[par[x]]+1;
    low[x]=level[x];
    vis[x]=1;
    for(int i:adj[x]){
        if(!vis[i]){
            par[i]=x;
            dfsLowLink(i);
            low[x]=min(low[x],low[i]);
            if(low[i]>=level[x]&&(x!=0)) Ti.insert(x);
        }
        else if(i!=par[x]) low[x]=min(low[x],level[i]);
    }
}
void dfsLowLinkBridge(int x){
    level[x]=level[par[x]]+1;
    low[x]=level[x];
    vis[x]=1;
    for(int i:adj[x]){
        if(!vis[i]){
            par[i]=x;
            dfsLowLinkBridge(i);
            low[x]=min(low[x],low[i]);
            if(low[i]>level[x]) bridge.insert({min(i,x),max(i,x)});
        }
        else if(i!=par[x]) low[x]=min(low[x],level[i]);
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    adj.resize(n+1);
    up(i,1,m){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfsLowLink(0);
    if(adj[0].size()>=2) Ti.insert(0);
    cout<<Ti.size()<<endl;
    for(int i:Ti) cout<<i<<' ';
    cout<<endl;
    reset(vis);
    reset(level);
    reset(low);
    dfsLowLinkBridge(0);
    cout<<bridge.size()<<endl;
    for(pii i:bridge) cout<<i.fi<<' '<<i.se<<endl;
    return 0;
}
