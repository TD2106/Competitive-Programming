#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define pb push_back
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
int n,m,x,X[100005],dis[100005],u,v,Ti=1e9;
vector<vi> adj;
bool vis[100005]={0};
void bfs(){
    dis[1]=0;
    for(int i=2;i<=n;i++) dis[i]=1e9;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        if(vis[temp]) continue;
        vis[temp]=1;
        for(int i=0;i<adj[temp].size();i++){
            if(!vis[adj[temp][i]]&&dis[adj[temp][i]]>dis[temp]+1){
                dis[adj[temp][i]]=dis[temp]+1;
                q.push(adj[temp][i]);
            }
        }
    }
}
bool cmp(int a,int b){
    return (dis[a]<dis[b]);
}
int main(){
	ios_base::sync_with_stdio(0);
	fr("REINVENT.INP");
	fw("REINVENT.OUT");
	cin>>n>>m>>x;
	adj.resize(n+1);
	for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
	}
	for(int i=1;i<=x;i++) cin>>X[i];
	bfs();
	sort(X+1,X+x+1,cmp);
	for(int i=2;i<=x;i++) Ti=min(dis[X[i]]-dis[X[i-1]],Ti);
	cout<<Ti<<endl;
	return 0;
}
