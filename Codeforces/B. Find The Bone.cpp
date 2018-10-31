#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
bool vis[1000005]={0},flag=0;
int n,m,k,u,v,Ti=1,t;
int main (){
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>t;
        vis[t]=1;
    }
    if(vis[1]){
        cout<<1<<endl;
        return 0;
    }
    for(int i=0;i<k;i++){
        cin>>u>>v;
        if(u!=Ti&&v!=Ti) continue;
        if(vis[u]&&!flag){
            Ti=u;
            flag=1;
        }
        if(vis[v]&&!flag){
            Ti=v;
            flag=1;
        }
        if(!flag&&Ti==u) Ti=v;
        else if(!flag&&Ti==v) Ti=u;
    }
    cout<<Ti<<endl;
}
