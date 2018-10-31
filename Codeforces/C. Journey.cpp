#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,u,v,totalLeaf=0;
vector< vector<int> > adj;
vector<int> totalDis;
map<int,int> cnt;
double Ti=0;
bool vis[100005]={0};
void dfs(int x,int dis,double p){
    bool flag=1;
    int child=0;
    vis[x]=1;
    for(int i=0;i<adj[x].size();i++){
        if(!vis[adj[x][i]]){
            flag=0;
            child++;
        }
    }
    for(int i=0;i<adj[x].size();i++){
        if(!vis[adj[x][i]]){
            dfs(adj[x][i],dis+1,p/(double)child);
        }
    }
    if(flag){
        Ti+=(double)dis*p;
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	if(n==1){
        cout<<0<<endl;
        return 0;
	}
	adj.resize(n+1);
	for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
	}
	dfs(1,0,1.000000);
	cout<<fixed<<setprecision(6)<<Ti<<endl;
	return 0;
}
