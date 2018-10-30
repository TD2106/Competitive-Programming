#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,m,u,v,Ti=0,t;
bool adj[3001][3001]={0};
vector< vector<int> > adjlist;
int cal(int i){
    if(i<2) return 0;
    else return i*(i-1)/2;
}
int main(){
    cin>>n>>m;
    adjlist.resize(n+1);
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u][v]=1;
        adjlist[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                t=0;
                for(int k=0;k<adjlist[i].size();k++){
                    if(adj[adjlist[i][k]][j]) t++;
                }
                Ti+=cal(t);
            }
        }
    }
    cout<<Ti<<endl;
    return 0;
}
