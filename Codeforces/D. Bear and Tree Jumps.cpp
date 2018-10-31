#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
vector< vector<int> > adj;
bool vis[200005]={0};
ll n,Ti=0,k;
int x,y;
void flood(int u,int j){
    if(j>k) return;
    Ti+=k*(k+1)/2;
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++){
        if(!vis[adj[u][i]]) flood(adj[u][i],j+1);
    }
    vis[u]=0;
}
int main(){
    cin>>n>>k;
    adj.resize(n+1);
    for(int i=1;i<=n-1;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
         flood(i,0);
         cout<<Ti<<" "<<i<<endl;
    }
    cout<<Ti/2<<endl;
    return 0;
}
