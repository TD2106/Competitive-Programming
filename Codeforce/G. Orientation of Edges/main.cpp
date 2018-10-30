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
typedef vector<pii> vpii;
int n,m,type,u,v,Timx[300005]={0},Timn[300005]={0},s,temp;
vector<vpii> adj;
vpii undirected;
set<int> mxReach,mnReach;
bool vis[300005];
pii direction[300005];
void bfs(set<int>& st){
    reset(vis);
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        if(st.size()==n) break;
        temp=q.front();
        q.pop();
        st.insert(temp);
        if(vis[temp]) continue;
        vis[temp]=1;
        for(auto t:adj[temp]){
            if(!vis[t.fi]){
                q.push(t.fi);
                direction[t.se]={temp,t.fi};
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&s);
    adj.resize(n+1);
    up(i,1,m){
        scanf("%d%d%d",&type,&u,&v);
        if(type==1) adj[u].pb({v,0});
        else undirected.pb({u,v});
    }
    bfs(mnReach);
    up(i,0,(int)undirected.size()-1){
        u=undirected[i].fi;
        v=undirected[i].se;
        if(mnReach.count(u)&&mnReach.count(v)||!(mnReach.count(u)||mnReach.count(v))) Timn[i+1]=1;
        else{
            if(mnReach.count(u)) Timn[i+1]=2;
            else Timn[i+1]=1;
        }
    }
    up(i,0,(int)undirected.size()-1){
        u=undirected[i].fi;
        v=undirected[i].se;
        adj[u].pb({v,i+1});
        adj[v].pb({u,i+1});
    }
    bfs(mxReach);
    up(i,0,(int)undirected.size()-1){
        if(direction[i+1]==undirected[i]) Timx[i+1]=1;
        else Timx[i+1]=2;
    }
    printf("%d\n",mxReach.size());
    up(i,0,(int)undirected.size()-1){
        if(Timx[i+1]==1) printf("+");
        else printf("-");
    }
    puts("");
    printf("%d\n",mnReach.size());
    up(i,0,(int)undirected.size()-1){
        if(Timn[i+1]==1) printf("+");
        else printf("-");
    }
    return 0;
}
