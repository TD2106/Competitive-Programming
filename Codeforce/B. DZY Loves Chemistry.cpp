#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;
ll dsu[55],s[55]={0},x,y,n,m,Ti=1;
ll finddsu(ll u){
    if(u==dsu[u]) return u;
    else return dsu[u] = finddsu(dsu[u]);
}
void uniondsu(ll u,ll v){
    ll a = finddsu(u);
    ll b = finddsu(v);
    //cout<<a<<" "<<b<<endl;
    if( a == v || b == u || a == b ) return;
    if(s[a]>=s[b]) dsu[b]=a,s[a]+=s[b],s[b]=0;
    else dsu[a]=b,s[b]+=s[a],s[a]=0;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) dsu[i]=i,s[i]=1;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        uniondsu(x,y);
    }
    //for(int i=1;i<=n;i++) cout<<s[i]<<endl;
    for(int i=1;i<=n;i++){
        if(s[i]<=1) continue;
        for(int j=2;j<=s[i];j++) Ti*=2;
    }
    cout<<Ti<<endl;
    return 0;
}



