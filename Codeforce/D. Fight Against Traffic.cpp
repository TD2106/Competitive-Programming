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
int n,m,s,t,u,v,minS[1005]={0},minT[1005]={0},Ti=0;
vector<vi> adj;
bool hasRoad[1005][1005]={0};
void dijkstra(int x,int *dis){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    up(i,1,n) dis[i]=1e9;
    pq.push({0,x});
    while(!pq.empty()){
        pii temp = pq.top();
        pq.pop();
        if(dis[temp.se]!=1e9) continue;
        dis[temp.se]=temp.fi;
        for(int i:adj[temp.se]){
            pq.push({dis[temp.se]+1,i});
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>s>>t;
    adj.resize(n+1);
    up(i,1,m){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        hasRoad[u][v]=1;
        hasRoad[v][u]=1;
    }
    dijkstra(s,minS);
    dijkstra(t,minT);
    up(i,1,n){
        up(j,i+1,n){
            if((minS[i]+minT[j]+1)>=minS[t]&&(minT[i]+minS[j]+1)>=minS[t]&&!hasRoad[i][j]){
                Ti++;
            }
        }
    }
    cout<<Ti<<endl;
    return 0;
}
