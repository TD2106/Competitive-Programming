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
int color[200005]={0},Ti=0,u,v,t,n,parent[200005]={0};
bool vis[200005]={0};
vector<vi> adj;
set<int> co;
queue<int> q;
int main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    adj.resize(n+1);
    adj[1].pb(0);
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vis[0]=vis[1]=1;
    color[1]=1;
    parent[1]=0;
    q.push(1);
    while(!q.empty()){
        co.clear();
        t=1;
        u=q.front();
        q.pop();
        co.ins(color[parent[u]]);
        co.ins(color[u]);
        for(int i=0;i<adj[u].size();i++){
            if(!vis[adj[u][i]]){
                while(co.count(t)) t++;
                color[adj[u][i]]=t;
                Ti=max(t,Ti);
                co.ins(t);
                q.push(adj[u][i]);
                vis[adj[u][i]]=1;
                parent[adj[u][i]]=u;
            }
        }
    }
    cout<<Ti<<endl;
    for(int i=1;i<=n;i++) cout<<color[i]<<" ";
    return 0;
}



