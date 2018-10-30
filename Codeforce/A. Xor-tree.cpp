#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define M 100005
using namespace std;
typedef long long int ll;
vector< vector<int> > adj;
vector<int> Ti;
int n,init[M],goal[M],u,v;
bool vis[M]={0};
void dfs(int x,int depth,int c){
    //if(x==27) cout<<depth<<" "<<c<<endl;
    vis[x]=1;
    if(c==2) init[x]=1-init[x];
    else if(c==1&&depth%2==0) init[x]=1-init[x];
    if(init[x]!=goal[x]){
        init[x]=goal[x];
        Ti.push_back(x);
        if(c==2) c=1,depth=1;
        else if(c==1&&depth%2==0) c=0;
        else if(c==1&&depth%2==1) c=2;
        else if(c==0) c=1,depth=0;
    }
    for(int i=0;i<adj[x].size();i++){
        if(!vis[adj[x][i]]) dfs(adj[x][i],depth+1,c);
    }
}
int main(){
    cin>>n;
    adj.resize(n+1);
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++) cin>>init[i];
    for(int i=1;i<=n;i++) cin>>goal[i];
    dfs(1,0,0);
    cout<<Ti.size()<<endl;
    for(int i=0;i<Ti.size();i++) cout<<Ti[i]<<" ";
    return 0;
}
