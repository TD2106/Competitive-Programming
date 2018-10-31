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
int n,u,v,in=0,level[3005]={0};
vector<vi> adj;
vi cycle;
bool vis[3005]={0};
void dfs(int x,int p){
    if(in) return;
    vis[x]=1;
    cycle.pb(x);
    for(int i:adj[x]){
        if(in) return;
        if(vis[i]&&i!=p){
            in=i;
            return;
        }
        else if(!vis[i]) dfs(i,x);
    }
    if(in) return;
    cycle.pop_back();
}
void dfs2(int x,int p){
    vis[x]=1;
    level[x]=level[p]+1;
    for(int i:adj[x]){
        if(!vis[i]){
             dfs2(i,x);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    adj.resize(n+1);
    up(i,1,n){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    reverse(all(cycle));
    while(!cycle.empty()){
        if(cycle[cycle.size()-1]!=in) cycle.pop_back();
        else break;
    }
    reset(vis);
    level[0]=-1;
    for(int i:cycle) vis[i]=1;
    for(int i:cycle){
        dfs2(i,0);
    }
    up(i,1,n) cout<<level[i]<<' ';
    return 0;
}
