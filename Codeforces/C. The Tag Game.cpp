#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define pb push_back
#define M 200005
using namespace std;
typedef long long int ll;
int d[M]={0},p[M],lowest[M]={0},n,Ti=0,x,y,b;
bool vis[M]={0};
vector< vector<int> > adj;
void dfs(int u,int parent){
    lowest[u]=d[u]=d[parent]+1;
    vis[u]=1;
    p[u]=parent;
    for(int i=0;i<adj[u].size();i++){
        if(!vis[adj[u][i]]){
            dfs(adj[u][i],u);
            lowest[u]=max(lowest[u],lowest[adj[u][i]]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>b;
    adj.resize(n+1);
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,0);
    x=d[b]/2-1;
    while(x--) b=p[b];
    Ti=lowest[b];
    Ti=2*(Ti-1);
    cout<<Ti<<endl;
	return 0;
}
