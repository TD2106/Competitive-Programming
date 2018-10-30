#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define reset(x) memset(x,0,sizeof(x)) // set all elements to 0
using namespace std;
typedef long long int ll;
int dist[10005],n,m,tc,u,v; //dist is distance from 1 to other node (island)
queue<int> q; // queue is used to push unprocessed islands
bool vis[10005]; //check to see if the island has been visited
vector< vector<int> > adjacentList;
void bfs(){
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        u=q.front(); // u is the first island in the queue
        q.pop(); // remove 1st island from queue
        for(int i=0;i<adjacentList[u].size();i++){
            if(!vis[adjacentList[u][i]]){
                dist[adjacentList[u][i]]=dist[u]+1; // distance from island to 1 equal from parent island plus 1
                q.push(adjacentList[u][i]);
                vis[adjacentList[u][i]]=1; // mark as visited
            }
        }
    }
}
int main(){
    cin>>tc;
    while(tc--){
        adjacentList.clear();
        reset(dist);
        reset(vis);
        cin>>n>>m;
        adjacentList.resize(n+1);
        for(int i=0;i<m;i++){
            cin>>u>>v;
            adjacentList[u].push_back(v);
            adjacentList[v].push_back(u);
        }
        bfs();
        cout<<dist[n]<<endl;
    }
    return 0;
}
