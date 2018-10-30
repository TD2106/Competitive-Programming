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
typedef pair<ll,pii> plii;
plii edges[200005],edge;
int n,m,dsu[100005],level[100005]={0};
ll Ti=5e18,alpha,path=0;
vector<vi> tree;
bool vis[100005]={0};
int findDSU(int x){
    if(dsu[x]==x) return x;
    else return dsu[x]=findDSU(dsu[x]);
}
void mergeDSU(int x,int y){
    x=findDSU(x);
    y=findDSU(y);
    if(x==y) return;
    dsu[x]=y;
}
void dfs(int x,int p){
    if(path) return;
    vis[x]=1;
    if(x==edge.se.se){
        path=p;
        return;
    }
    for(int i:tree[x]){
        if(!vis[i]) dfs(i,p+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>alpha;
    tree.resize(n+1);
    up(i,1,m) cin>>edges[i].se.fi>>edges[i].se.se>>edges[i].fi;
    sort(edges+1,edges+1+m);
    up(i,1,n) dsu[i]=i;
    up(i,1,m){
        if(findDSU(edges[i].se.fi)!=findDSU(edges[i].se.se)){
            mergeDSU(edges[i].se.fi,edges[i].se.se);
            tree[edges[i].se.fi].pb(edges[i].se.se);
            tree[edges[i].se.se].pb(edges[i].se.fi);
        }
        else{
            edge = edges[i];
            dfs(edge.se.fi,0);
            Ti=min(Ti,(path+1)*alpha+edge.fi*edge.fi);
            break;
        }
    }
    if(Ti!=5e18) cout<<Ti<<endl;
    else cout<<"Poor girl";
    return 0;
}
