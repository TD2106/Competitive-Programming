#include <bits/stdc++.h>
#define M 200005
#define mod 1000000007
using namespace std;
typedef long long ll;
ll n,a[M],Ti=0,vis[M]={0},totalCycleVertices=0,startCycle,cycleVertices;
bool hasCycle;
void dfs1(int u){
    if(vis[u]==1){
        hasCycle=1;
        startCycle=u;
        return;
    }
    else if(vis[u]==0){
        vis[u]=1;
        dfs1(a[u]);
        vis[u]=2;
    }

}
void dfs2(ll u){
    cycleVertices=1;
    ll v=a[u];
    while(v!=u){
        cycleVertices++;
        v=a[v];
    }
}
ll fastExponential(ll base,ll power){
    ll ans=1;
    while(power){
        if(power%2==1) ans*=base,ans%=mod;
        base*=base,base%=mod;
        power/=2;
    }
    return ans;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            hasCycle=0;
            dfs1(i);
            if(hasCycle){
                dfs2(startCycle);
                if(Ti==0) Ti+=(fastExponential(2,cycleVertices)-2+mod)%mod;
                else Ti*=(fastExponential(2,cycleVertices)-2+mod)%mod;
                Ti%=mod;
                totalCycleVertices+=cycleVertices;
            }
        }
    }
    if(Ti==0) Ti=fastExponential(2,n);
    else Ti*=fastExponential(2,n-totalCycleVertices);
    Ti%=mod;
    cout<<Ti<<endl;
    return 0;
}
