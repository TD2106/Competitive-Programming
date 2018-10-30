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
int n,m,k,Ti,level[200005]={0},parent[200005][20]={0},u,v,dsu[200005];
vector<vi> adj;
bool vis[200005]={0};
void dfs(int x,int p){
    level[x]=level[p]+1;
    parent[x][0]=p;
    vis[x]=1;
    for(int i:adj[x]){
        if(!vis[i]){
            dfs(i,x);
        }
    }
}
int find(int x){
    if(dsu[x]==x) return x;
    else return dsu[x]=find(dsu[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    dsu[x]=y;
}
int walk(int s,int l){
    up(i,0,19){
        if((l>>i)&1) s=parent[s][i];
    }
    return s;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    adj.resize(n+1);
    up(i,1,n) dsu[i]=i;
    up(i,1,k){
        cin>>u>>v;
        merge(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    up(i,1,n){
        if(!vis[i]) dfs(i,0);
    }
    up(i,1,19){
        up(j,1,n) parent[j][i]=parent[parent[j][i-1]][i-1];
    }
    cin>>m;
    while(m--){
        cin>>u>>v;
        if(find(u)!=find(v)) Ti=-1;
        else{
            if(level[v]<=level[u]) Ti=parent[u][0];
            else{
                int temp=level[v]-level[u];
                if(walk(v,temp)==u) Ti=walk(v,temp-1);
                else Ti=parent[u][0];
            }
        }
        cout<<Ti<<endl;
    }
    return 0;
}
