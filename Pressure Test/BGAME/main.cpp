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
typedef pair<int,pii> piii;
typedef vector<pii> vpii;
vector<vpii> tree;
int level[100005]={0},n,m,dsu[100005],u,v,val,Ti=0;
pii parent[100005][20];
piii edges[100005];
bool vis[100005]={0},notInTree[100005]={0};
int find(int x){
    if(dsu[x]==x) return x;
    else return dsu[x]=find(dsu[x]);
}
int merge(int x,int y){
    x=find(x);
    y=find(y);
    dsu[x]=y;
}
void dfs(int x,int p,int val){
    vis[x]=1;
    level[x]=level[p]+1;
    parent[x][0]={p,val};
    for(auto temp:tree[x]){
        if(!vis[temp.fi]){
            dfs(temp.fi,x,temp.se);
        }
    }
}
void lcaPrecompute(){
    up(i,1,19){
        up(j,1,n){
            int temp=parent[j][i-1].fi;
            parent[j][i]={parent[temp][i-1].fi,max(parent[temp][i-1].se,parent[j][i-1].se)};
        }
    }
}
pii walk(int x,int length){
    int res=0;
    up(i,0,19){
        if(length&(1<<i)){
            res=max(res,parent[x][i].se);
            x=parent[x][i].fi;
        }
    }
    return {x,res};
}
int lca(int x,int y){
    if(level[x]>level[y]) x=(walk(x,level[x]-level[y]).fi);
    else y=(walk(y,level[y]-level[x]).fi);
    down(i,19,0){
        if(parent[x][i].fi!=parent[y][i].fi){
            x=parent[x][i].fi;
            y=parent[y][i].fi;
        }
    }
    while(x!=y) x=parent[x][0].fi,y=parent[y][0].fi;
    return x;
}
int main(){
    ios_base::sync_with_stdio(0);
    fr("BGAME.INP");
    fw("BGAME.OUT");
    cin>>n>>m;
    tree.resize(n+1);
    up(i,1,n) dsu[i]=i;
    up(i,1,m){
        cin>>edges[i].se.fi>>edges[i].se.se>>edges[i].fi;
    }
    sort(edges+1,edges+1+m,greater<piii>());
    up(i,1,m){
        u=edges[i].se.fi,v=edges[i].se.se,val=edges[i].fi;
        if(find(u)!=find(v)){
            tree[u].pb({v,val});
            tree[v].pb({u,val});
            merge(u,v);
        }
        else notInTree[i]=1;
    }
    up(i,1,n){
        if(!vis[i]) dfs(i,0,0);
    }
    lcaPrecompute();
    up(i,1,m){
        if(notInTree[i]){
            u=edges[i].se.fi;
            v=edges[i].se.se;
            int temp=lca(u,v);
            Ti=max(Ti,max(walk(u,level[u]-level[temp]).se,walk(v,level[v]-level[temp]).se)+edges[i].fi);
        }
    }
    cout<<Ti<<endl;
    return 0;
}
