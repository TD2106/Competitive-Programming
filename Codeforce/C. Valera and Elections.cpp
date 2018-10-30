#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long int ll;
vector< vector< pair<int,int> > > adj;
int n,x,y,t,Ti[100005]={0},c=0,total=0;
bool vis[100005]={0};
void dfs(int u){
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++){
        if(vis[adj[u][i].first]) continue;
        if(adj[u][i].second==2) c++;
        dfs(adj[u][i].first);
        if(adj[u][i].second==2) Ti[adj[u][i].first]=c,c=0;
    }
}
int main(){
    cin>>n;
    adj.resize(n+1);
    for(int i=0;i<n-1;i++){
        cin>>x>>y>>t;
        adj[y].pb(mp(x,t));
        adj[x].pb(mp(y,t));
    }
    dfs(1);
    for(int i=1;i<=n;i++) if(Ti[i]) total++;
    cout<<total<<endl;
    for(int i=1;i<=n;i++) if(Ti[i]) cout<<i<<" ";
    return 0;
}
