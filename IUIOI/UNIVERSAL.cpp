#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
int n,m,testcase,u,v,p[10005],sum;
vector< vector<int> > adj;
bool flag,vis[10005];
void dfs(int x){
    vis[x]=1;
    sum+=p[x];
    for(int i=0;i<adj[x].size();i++){
        if(!vis[adj[x][i]]){
            dfs(adj[x][i]);
        }
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	fr("UNIVERSAL.INP");
	fw("UNIVERSAL.OUT");
	cin>>testcase;
	for(int tc=1;tc<=testcase;tc++){
        cin>>n>>m;
        adj.clear();
        reset(vis);
        adj.resize(n);
        flag=1;
        for(int i=0;i<n;i++) cin>>p[i];
        for(int i=0;i<m;i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                sum=0;
                dfs(i);
                if(sum!=0) flag=0;
            }
        }
        cout<<"Person "<<tc<<": ";
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
	}
	return 0;
}
