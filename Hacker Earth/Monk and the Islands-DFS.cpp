#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define reset(x) memset(x,0,sizeof(x)) // set all elements to 0
using namespace std;
typedef long long int ll;
int Ti=1e9,n,m,tc,u,v,t;
bool vis[10005]; //check to see if the island has been visited
vector< vector<int> > adjacentList;
void dfs(int u){ //dfs from u is starting from u and goes to all its connected island deep down
    vis[u]=1;
    if(u!=1) t++; // if island not 1 then increase the distance
    if(u==n) Ti=min(Ti,t);
    else{
        for(int i=0;i<adjacentList[u].size();i++){
            if(!vis[adjacentList[u][i]]){
                dfs(adjacentList[u][i]);
            }
        }
    }
    vis[u]=0; // we leave the island then we mark it as unvisited
    t--; // we leave the island then we decrease the distance
}
int main(){
    cin>>tc;
    while(tc--){
        adjacentList.clear();
        Ti=1e9,t=0;
        reset(vis);
        cin>>n>>m;
        adjacentList.resize(n+1);
        for(int i=0;i<m;i++){
            cin>>u>>v;
            adjacentList[u].push_back(v);
            adjacentList[v].push_back(u);
        }
        dfs(1);
        cout<<Ti<<endl;
    }
    return 0;
}
