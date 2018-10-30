#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
#define M 100005
using namespace std;
int dsu[M],n,k,Ti=0,x,y;
int finddsu(int u){
    if(dsu[u] == u) return u;
    else return dsu[u] = finddsu(dsu[u]);
}
void uniondsu(int u,int v){
    int a,b;
    a=finddsu(u);
    b=finddsu(v);
    dsu[b]=a;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) dsu[i]=i;
    while(k--){
        cin>>x>>y;
        uniondsu(x,y);
    }
    for(int i=1;i<=n;i++) if(dsu[i]==i) Ti++;
    cout<<Ti<<endl;
    return 0;
}



