#include <bits/stdc++.h>
#define bug(x) cout<<#x<<" = "<<x<<endl
#define M 200005
using namespace std;
typedef vector<int> vi;
int Ti[M]={0},u,n;
bool vis[M]={0};
vector<vi> adj;
queue<int> q;
void bfs(){
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            if(!vis[adj[u][i]]){
                Ti[adj[u][i]]=Ti[u]+1;
                vis[adj[u][i]]=1;
                q.push(adj[u][i]);
            }
        }
    }
}
int main (){
    cin>>n;
    adj.resize(n+1);
    for(int i=1;i<=n;i++){
        if(i!=n) adj[i].push_back(i+1);
        if(i!=1) adj[i].push_back(i-1);
        cin>>u;
        if(abs(u-i)>1) adj[i].push_back(u);
    }
    bfs();
    for(int i=1;i<=n;i++) cout<<Ti[i]<<" ";
    return 0;
}
