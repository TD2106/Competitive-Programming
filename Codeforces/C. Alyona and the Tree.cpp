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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n,a[100005],dist[100005]={0},p,c,Ti=0,child[100005]={0};
vector<pll> adj[100005];
bool vis[100005]={0};
void dfs(int x,int parent,ll cost){
    vis[x]=1;
    dist[x]=cost+dist[parent];
    for(auto temp:adj[x]){
        if(!vis[temp.fi]){
            dfs(temp.fi,x,temp.se);
            child[x]+=child[temp.fi];
        }
    }
    child[x]++;
}
void dfs2(int x,ll mins){
    vis[x]=1;
    if(dist[x]-mins>a[x]){
        Ti+=child[x];
        return;
    }
    for(auto temp:adj[x]){
        if(!vis[temp.fi]) dfs2(temp.fi,min(dist[x],mins));
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	up(i,1,n) cin>>a[i];
	up(i,2,n){
        cin>>p>>c;
        adj[i].pb({p,c});
        adj[p].pb({i,c});
	}
	dfs(1,0,0);
	reset(vis);
	dfs2(1,0);
	cout<<Ti<<endl;
	return 0;
}
