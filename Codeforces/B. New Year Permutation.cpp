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
int n,a[301],m;
string adj[301];
bool vis[301];
void dfs(int i){
    vis[i]=1;
    m=min(m,a[i]);
    for(int j=1;j<=n;j++){
        if(!vis[j]&&adj[i][j]=='1') dfs(j);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>adj[i];
        adj[i]="."+adj[i];
    }
    for(int i=1;i<=n;i++){
        m=a[i];
        dfs(i);
        for(int j=i;j<=n;j++){
            if(a[j]==m){
                swap(a[i],a[j]);
                break;
            }
        }
        for(int j=i+1;j<=n;j++) vis[j]=0;
        vis[i]=1;
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}



