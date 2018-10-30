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
bool vis[100005]={0};
vector<vi> adj;
int n,c[100005]={0},cloc[100005]={0},color,t,Ti[100005]={0};
void dfs(int st){
    vis[st]=1;
    Ti[st]=cloc[c[st]];
    cloc[c[st]]=st;
    for(int i=0;i<adj[st].size();i++){
        if(!vis[adj[st][i]]) dfs(adj[st][i]);
    }
    cloc[c[st]]=Ti[st];
}
int main(){
    cin>>n>>color;
    adj.resize(n+1);
    for(int i=2;i<=n;i++){
        cin>>t;
        adj[i].pb(t);
        adj[t].pb(i);
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=color;i++) cloc[i]=-1;
    dfs(1);
    for(int i=1;i<=n;i++) cout<<Ti[i]<<" ";
    return 0;
}



