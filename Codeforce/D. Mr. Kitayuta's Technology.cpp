#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
vector<vi> dir,adj;
vi vertex;
int n,m,u,v,Ti=0,vis[100005]={0};
bool isCycle,visited[100005]={0};
void dfs2(int x){
    visited[x]=1;
    vertex.push_back(x);
    for(int i=0;i<adj[x].size();i++){
        if(!visited[adj[x][i]]){
            dfs2(adj[x][i]);
        }
    }
}
void dfs(int x){
    vis[x]=1;
    for(int i=0;i<dir[x].size();i++){
        if(vis[dir[x][i]]==0) dfs(dir[x][i]);
        else if(vis[dir[x][i]]==1){
            isCycle=1;
        }
    }
    vis[x]=2;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	adj.resize(n+1);
	dir.resize(n+1);
	while(m--){
        cin>>u>>v;
        dir[u].push_back(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vertex.clear();
            isCycle=0;
            dfs2(i);
            for(int j=0;j<vertex.size();j++){
                if(!vis[vertex[j]]) dfs(vertex[j]);
            }
            if(isCycle) Ti+=vertex.size();
            else Ti+=vertex.size()-1;
        }
	}
	cout<<Ti<<endl;
	return 0;
}
