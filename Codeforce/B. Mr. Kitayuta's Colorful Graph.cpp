#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;
struct DSU{
    int a[105];
    void init(int n){
        for(int i=1;i<=n;i++) a[i]=i;
    }
    int finddsu(int u){
        if(u==a[u]) return u;
        else return a[u] = finddsu(a[u]);
    }
    void uniondsu(int u,int v){
        int x = finddsu(u);
        int y = finddsu(v);
        a[x]=y;
    }
    bool isConnect(int u,int v){
        if(finddsu(u)==finddsu(v)) return 1;
        else return 0;
    }
};
int main(){
    DSU u[105];
    int n,m,x,y,c,q,Ti;
    cin>>n>>m;
    for(int i=1;i<=m;i++) u[i].init(n);
    for(int i=1;i<=m;i++){
        cin>>x>>y>>c;
        u[c].uniondsu(x,y);
    }
    cin>>q;
    while(q--){
        Ti=0;
        cin>>x>>y;
        for(int i=1;i<=m;i++) if(u[i].isConnect(x,y)) Ti++;
        cout<<Ti<<endl;
    }
    return 0;
}



