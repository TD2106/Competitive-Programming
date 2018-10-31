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
vector< set<int> > adj;
int n,m,u,v,vis[505]={0},c=0;
vi cycle;
bool Ti=0;
void dfs1(int x){
    if(c) return;
    vis[x]=1;
    cycle.pb(x);
    for(int i:adj[x]){
        if(c) return;
        if(vis[i]==1){
            c=i;
            cycle.pb(i);
            return;
        }
        else if(vis[i]==0) dfs1(i);
    }
    if(c) return;
    cycle.pop_back();
    vis[x]=2;
}
void dfs2(int x){
    if(Ti) return;
    vis[x]=1;
    for(int i:adj[x]){
        if(vis[i]==1){
            Ti=1;
            return;
        }
        else if(vis[i]==0) dfs2(i);
    }
    if(Ti) return;
    vis[x]=2;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    adj.resize(n+1);
    up(i,1,m){
        cin>>u>>v;
        adj[u].insert(v);
    }
    up(i,1,n){
        if(!vis[i]&&!c){
            dfs1(i);
        }
    }
    if(!c){
        cout<<"Yes\n";
        return 0;
    }
    while(cycle[0]!=c){
        cycle.erase(cycle.begin());
    }
//    for(int i:cycle) cout<<i<<' ';
//    cout<<endl;
    up(i,0,cycle.size()-2){
        adj[cycle[i]].erase(cycle[i+1]);
        reset(vis);
        Ti=0;
        up(j,1,n){
            if(!vis[j]) dfs2(j);
        }
        if(!Ti){
            cout<<"Yes\n";
            return 0;
        }
        adj[cycle[i]].insert(cycle[i+1]);
    }
    cout<<"No\n";
    return 0;
}
