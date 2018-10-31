#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
int n,m,dsu[300005],l,r,x,Ti[300005]={0};
int finddsu(int u){
    if(u==dsu[u]) return u;
    else return dsu[u]=finddsu(dsu[u]);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) dsu[i]=i;
    dsu[n+1]=n+1;
    for(int i=1;i<=m;i++){
        cin>>l>>r>>x;
        for(int j=finddsu(l);j<=r;j=finddsu(j+1)){
            if(j!=x){
                dsu[j]=j+1;
                Ti[j]=x;
            }
            //cout<<j<<endl;
        }
    }
    //cout<<123<<endl;
    for(int i=1;i<=n;i++) cout<<Ti[i]<<" ";
    return 0;
}



