#include <bits/stdc++.h>
using namespace std;
int n,m,c[100005],Ti,mx=-1,x,y;
vector<vector<int> > adj;
set<int> nei[100005];
bool vis[100005]={0};
void dfs(int u){
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++){
        if(c[adj[u][i]]!=c[u]) nei[c[u]].insert(c[adj[u][i]]);
        if(!vis[adj[u][i]]) dfs(adj[u][i]);
    }
}
int main (){
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
    for(int i=1;i<=n;i++){
        if((int)nei[c[i]].size()>mx){
            Ti=c[i];
            mx=(int)nei[c[i]].size();
        }
        else if((int)nei[c[i]].size()==mx) Ti=min(Ti,c[i]);
    }
    cout<<Ti<<endl;
}
