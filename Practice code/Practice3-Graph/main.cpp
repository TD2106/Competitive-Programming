#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,l,r) for(int i=r;i>=l;i--)
#define reset(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define fi first
#define se second
#define endl '\n'
#define bug(x) cout<< #x << " = " << x <<endl
#define pb push_back
#define mp make_pair
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define tc() int tc;cin>>tc;up(_tc,1,tc)
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> orderedSet;
typedef pair<int,pii> piii;
//vector<vi> adj,reverseAdj;
int n,m,u,v,d,dist[105][105]={0};
bool vis[100005]={0};
//vector<vpii> adj;
vector<piii> edges;
//void dfs(int x){
//    vis[x]=1;
//    for(int i:adj[x]){
//        if(!vis[i]) dfs(i);
//    }
//}
//void bfs(int x){
//    queue<int> q;
//    q.push(x);
//    while(!q.empty()){
//        int temp = q.front();
//        q.pop();
//        if(vis[temp]) continue;
//        vis[temp]=1;
//        for(int i:adj[temp]){
//            if(!vis[i]) q.push(i);
//        }
//    }
//}
//void dijkstra(int x){
//    priority_queue<pii,vector<pii>,greater<pii> > pq;
//    up(i,1,n) dist[i]=1e9;
//    dist[x]=0;
//    pq.push({0,x});
//    while(!pq.empty()){
//        pii temp = pq.top();
//        pq.pop();
//        if(vis[temp.se]) continue;
//        vis[temp.se]=1;
//        dist[temp.se] = temp.fi;
//        for(pii i:adj[temp.se]){
//            if(dist[i.se] > temp.fi + i.fi){
//                dist[i.se] =i.fi + temp.fi;
//                pq.push({dist[i.se],i.se});
//            }
//        }
//    }
//}
//void bellmanFord(int x){
//    up(i,1,n) dist[i]=1e9;
//    dist[x]=0;
//    up(times,1,n-1){
//        for(piii edge:edges){
//            dist[edge.se.se] = min(dist[edge.se.se],dist[edge.se.fi]+edge.fi);
//        }
//    }
//}
//void floyd(){
//    up(k,1,n) up(i,1,n) up(j,1,n) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
//}
int main(){
    ios_base::sync_with_stdio(0);
//    fw("test.txt");
//    cout<<123<<endl;
    cin>>n>>m;
    up(i,1,n) up(j,1,n) dist[i][j]=1e9;
    up(i,1,n) dist[i][i]=0;
    up(i,1,m){
        cin>>u>>v>>d;
        dist[u][v]=min(d,dist[u][v]);
        dist[v][u]=min(d,dist[v][u]);
    }
//    up(i,1,n){
//        bug(i);
//        for(pii j:adj[i]) cout<<j.fi<<' '<<j.se<<endl;
//    }
    floyd();
//    up(i,1,n){
//        up(j,1,n){
//            bug(i);
//            bug(j);
//            bug(dist[i][j]);
//        }
//    }
    return 0;
}
