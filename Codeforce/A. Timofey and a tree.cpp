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
vector<vi> adj;
int main(){
    ios_base::sync_with_stdio(false);
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
            if(c[i]!=c[adj[i][j]]) sum++;
        }
    }
    sum/=2;
    for(int i=1;i<=n;i++){
        Ti=0;
        for(int j=0;j<adj[i].size();j++)
            if(c[i]!=c[adj[i][j]]) Ti++;
        if(Ti==sum){
            cout<<"YES\n"<<i<<endl;
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}



