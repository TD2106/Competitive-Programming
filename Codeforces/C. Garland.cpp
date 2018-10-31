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
ll sum=0,u,v,b[1000005],ans1=-1,ans2=-1;
int root,n;
queue<int> q;
vector<vi> adj;
void dfs(int st){
    //cout<<st<<" "<<r<<endl;
    for(int i=0;i<adj[st].size();i++){
        dfs(adj[st][i]);
        b[st]+=b[adj[st][i]];
    }
    if(b[st]==sum/3){
        if(ans1==-1) ans1=st;
        else if(ans2==-1) ans2=st;
        b[st]=0;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    adj.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>u>>v;
        sum+=v;
        b[i]=v;
        if(u==0) root=i;
        else adj[u].pb(i);
    }
    /*for(int i=1;i<=n;i++){
        for(int j=0;j<adj[i].size();j++) cout<<adj[i][j]<<" ";
        cout<<endl;
    }*/
    if(sum%3!=0){
        cout<<-1<<endl;
        return 0;
    }
    else dfs(root);
    //for(int i=1;i<=n;i++) cout<<bright[i]<<" ";
    if(ans1==-1||ans2==-1||ans1==root||ans2==root) cout<<-1<<endl;
    else cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
