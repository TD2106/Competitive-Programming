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
#define M 200005
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
int n,level[M]={0},Ti[M]={0},a[M]={0},u,v;
vector<pii> divisor;
vector<vi> adj;
bool vis[M]={0};
void dfs(int x,int parent){
    if(x==1) Ti[x]=0;
    else Ti[x]=__gcd(a[x],Ti[parent]);
    level[x]=level[parent]+1;
    vis[x]=1;
    for(int i:adj[x]){
        if(!vis[i]){
            dfs(i,x);
        }
    }
}
void dfs2(int x){
    vis[x]=1;
    for(int i=0;i<divisor.size();i++){
        if(a[x]%divisor[i].fi==0) divisor[i].se++;
        if(divisor[i].se>=(level[x]-1)) Ti[x]=max(Ti[x],divisor[i].fi);
    }
    for(int i:adj[x]){
        if(!vis[i]) dfs2(i);
    }
    for(int i=0;i<divisor.size();i++){
        if(a[x]%divisor[i].fi==0) divisor[i].se--;
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	adj.resize(n+1);
	up(i,1,n) cin>>a[i];
	up(i,1,n-1){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
	}
	dfs(1,0);
	reset(vis);
	for(int i=1;i*i<=a[1];i++){
        if(a[1]%i==0){
            divisor.pb({i,0});
            if(i!=a[1]/i) divisor.pb({a[1]/i,0});
        }
	}
	dfs2(1);
	up(i,1,n) cout<<Ti[i]<<" ";
	return 0;
}
