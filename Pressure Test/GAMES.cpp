#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
int n,m,u,v,s,t,Ti=1e9,a,b,d;
vector< vector<pii> > adj;
int dijsktra(int x,int y){
    int dis[1005];
    bool vis[1005]={0};
    for(int i=1;i<=n;i++) dis[i]=1e9;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push(mp(0,x));
    while(!pq.empty()){
        pii temp=pq.top();
        pq.pop();
        if(vis[temp.second]) continue;
        dis[temp.second]=temp.first;
        vis[temp.second]=1;
        for(int i=0;i<adj[temp.second].size();i++){
            if(!vis[adj[temp.second][i].second]){
                pq.push(mp(temp.first+adj[temp.second][i].first,adj[temp.second][i].second));
            }
        }
    }
    return dis[y];
}
int main(){
	ios_base::sync_with_stdio(0);
	fr("GAMES.INP");
	fw("GAMES.OUT");
    cin>>n>>m;
    adj.resize(n+1);
    cin>>s>>t>>a>>b;
    for(int i=0;i<m;i++){
        cin>>u>>v>>d;
        adj[u].pb(mp(d,v));
        adj[v].pb(mp(d,u));
    }
    Ti=min(Ti,dijsktra(s,a)+dijsktra(t,b));
    Ti=min(Ti,dijsktra(s,b)+dijsktra(t,a));
    if(Ti==1e9) Ti=-1;
    cout<<Ti<<endl;
	return 0;
}
