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
int n,m,u,v,idx=1,Ti=0;
bool vis[100005]={0};
vector<vi> adj,reverseAdj,scc;
vi listOfNodes;
void dfs(int x){
    vis[x]=1;
    for(int i:adj[x]){
        if(!vis[i]) dfs(i);
    }
    listOfNodes.pb(x);
}
void korasaju(int x,int num){
    vis[x]=1;
    scc[num].pb(x);
    for(int i:reverseAdj[x]){
        if(!vis[i]) korasaju(i,num);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    adj.resize(n+1);
    reverseAdj.resize(n+1);
    scc.resize(n+1);
    up(i,1,m){
        cin>>u>>v;
        adj[u].pb(v);
        reverseAdj[v].pb(u);
    }
    up(i,1,n){
        if(!vis[i]) dfs(i);
    }
    reverse(all(listOfNodes));
    reset(vis);
    for(int i:listOfNodes){
        if(!vis[i]){
            korasaju(i,++Ti);
        }
    }
    cout<<Ti<<endl;
    return 0;
}
