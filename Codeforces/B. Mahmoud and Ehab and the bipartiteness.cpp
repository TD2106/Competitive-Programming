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
typedef vector<int> vi;
int n,child[100005]={0},u,v,part[2]={0},in[100005];
ll Ti=0;
vector<vi> adj;
bool vis[100005]={0};
void dfs(int x,int group){
    vis[x]=1;
    part[group]++;
    in[x]=group;
    for(int i:adj[x]){
        if(!vis[i]){
            child[x]++;
            dfs(i,(group+1)%2);
        }
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	adj.resize(n+1);
	up(i,1,n-1){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
	}
	dfs(1,0);
	up(i,1,n){
        Ti+=(ll)(part[(in[i]+1)%2]-child[i]);
        if(i!=1) Ti--;
	}
	cout<<Ti/2<<endl;
	return 0;
}
