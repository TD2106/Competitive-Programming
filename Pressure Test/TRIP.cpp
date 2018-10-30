#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
vector< vector<pii> > adj;
int n,m,Ti,u,v,d;
bool vis[105];
void modDFS(int root,int x,int cost,int num){
    //cout<<root<<" "<<x<<" "<<cost<<" "<<num<<endl;
    if(cost>Ti) return;
    if(x==root&&vis[x]==1){
         Ti=min(Ti,cost);
         return;
    }
    vis[x]=1;
    for(int i=0;i<adj[x].size();i++){
        if(!vis[adj[x][i].F]||(adj[x][i].F==root&&num>=3)){
            modDFS(root,adj[x][i].F,cost+adj[x][i].S,num+1);
        }
    }
    vis[x]=0;
}
int main(){
	ios_base::sync_with_stdio(0);
	fr("TRIP.INP");
	fw("TRIP.OUT");
	cin>>n;
	while(n!=-1){
        cin>>m;
        Ti=2e9;
        adj.clear();
        adj.resize(n+1);
        for(int i=0;i<m;i++){
            cin>>u>>v>>d;
            adj[u].pb(mp(v,d));
            adj[v].pb(mp(u,d));
        }
        for(int i=1;i<=n;i++) modDFS(i,i,0,1);
        if(Ti==2e9) Ti=-1;
        cout<<Ti<<endl;
        cin>>n;
	}
	return 0;
}
