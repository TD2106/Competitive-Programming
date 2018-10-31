#include <bits/stdc++.h>
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define reset(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define pb push_back
#define ins insert
#define mp make_pair
#define fi first
#define se second
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
int n,u,v,c[100005]={0},sum=0,Ti=0;
bool vis[100005],flag;
set<int> difcolor;
vector<vi> adj;
void dfs(int st,int t){
    if(!flag) return;
    vis[t]=1;
    if(c[st]!=c[t]){
        flag = 0;
        return;
    }
    for(int i=0;i<adj[t].size();i++){
        if(!flag) return;
        if(!vis[adj[t][i]]) dfs(st,adj[t][i]);
    }
}
int main(){
    cin>>n;
    adj.resize(n+1);
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<adj[i].size();j++){
            if(c[i]!=c[adj[i][j]]){
                if(difcolor.empty()){
                    difcolor.insert(i);
                    difcolor.insert(adj[i][j]);
                }
                else{
                    if(difcolor.count(i)==0&&difcolor.count(adj[i][j])==0){
                        cout<<"NO\n";
                        return 0;
                    }
                    else{
                        difcolor.insert(i);
                        difcolor.insert(adj[i][j]);
                    }
                }
            }
        }
    }
    if(difcolor.empty()){
        cout<<"YES\n1";
        return 0;
    }
    for(set<int>::iterator itr=difcolor.begin();itr!=difcolor.end();itr++){
        flag=1;
        reset(vis);
        vis[*itr]=1;
        for(int i=0;i<adj[*itr].size();i++) dfs(adj[*itr][i],adj[*itr][i]);
        if(flag){
            cout<<"YES\n"<<*itr;
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}



