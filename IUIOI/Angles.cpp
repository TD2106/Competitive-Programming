#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,k,t;
vector<int> angle;
bool vis[365]={0};
void dfs(int u){
    if(vis[u]) return;
    vis[u]=1;
    for(int i=0;i<angle.size();i++){
        dfs((u+angle[i])%360);
        dfs((u-angle[i]+360)%360);
    }
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>t;
        t%=360;
        angle.push_back(t);
    }
    dfs(0);
    while(k--){
        cin>>t;
        t%=360;
        if(vis[t]) cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}
