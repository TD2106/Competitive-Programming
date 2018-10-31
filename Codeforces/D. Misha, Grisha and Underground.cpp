#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
int n,Ti,u,q,parent[20][100005]={0},level[100005]={0};
vector<vi> adj;
bool vis[100005]={0};
void dfs(int x,int p){
    level[x]=level[p]+1;
    parent[0][x]=p;
    vis[x]=1;
//    cout<<x<<" "<<level[x]<<endl;
    for(int i=0;i<adj[x].size();i++){
        if(!vis[adj[x][i]]){
            dfs(adj[x][i],x);
        }
    }
}
int lca(int x,int y){
    for(int i=19;i>=0;i--){
        if(level[parent[i][x]]>=level[y]) x=parent[i][x];
    }
    for(int i=19;i>=0;i--){
        if(level[parent[i][y]]>=level[x]) y=parent[i][y];
    }
    for(int i=19;i>=0;i--){
        if(parent[i][x]!=parent[i][y]){
            x=parent[i][x];
            y=parent[i][y];
        }
    }
    while(x!=y){
        x=parent[0][x];
        y=parent[0][y];
    }
    return x;
}
void solve(int a,int b,int c){
    int t1,t2,t3,t4;
    t1=lca(a,b);
    t2=lca(c,b);
    t3=lca(a,c);
    t4=max(0,level[t3]-max(level[t1],level[t2]));
    Ti=max(Ti,t4+level[b]-max(level[t1],level[t2])+1);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>q;
	adj.resize(n+1);
	for(int i=2;i<=n;i++){
        cin>>u;
        adj[u].push_back(i);
        adj[i].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=19;i++){
        for(int j=1;j<=n;j++){
            parent[i][j]=parent[i-1][parent[i-1][j]];
        }
	}
	while(q--){
        int x,y,z;
        cin>>x>>y>>z;
        Ti=0;
        solve(x,y,z);
        solve(y,x,z);
        solve(y,z,x);
        cout<<Ti<<endl;
	}
	return 0;
}
