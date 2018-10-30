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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll dis[100005]={0},n,a,b,c,toClass[100005]={0},Ti=0,sum=0;
bool vis[100005]={0};
vector< vector<pll> > adj;
void dijsktra(){
    up(i,1,n) dis[i]=1e18;
    priority_queue<pll> pq;
    pq.push({0LL,0LL});
    while(!pq.empty()){
        pll temp=pq.top();
        pq.pop();
        if(vis[temp.se]) continue;
        vis[temp.se]=1;
        dis[temp.se]=temp.fi;
        for(auto t:adj[temp.se]){
            if(!vis[t.se]) pq.push({temp.fi+t.fi,t.se});
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    adj.resize(n+1);
    up(i,0,n) cin>>toClass[i];
    up(i,1,n){
        cin>>a>>b>>c;
        adj[a].pb({c,b});
        adj[b].pb({c,a});
        sum+=c;
    }
    Ti=2*sum+toClass[0];
    dijsktra();
    up(i,1,n) Ti=min(Ti,2*sum-dis[i]+toClass[i]);
    cout<<Ti<<endl;
    return 0;
}
