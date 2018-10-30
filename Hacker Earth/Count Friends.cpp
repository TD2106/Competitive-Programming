#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
#define M 100005
using namespace std;
int n,m,dsu[M]={0},s[M]={0},x,y;
int finddsu(int u){
    if(dsu[u] == u) return u;
    else return dsu[u] = finddsu(dsu[u]);
}
void uniondsu(int u,int v){
    int a,b;
    a=finddsu(u);
    b=finddsu(v);
    if(a==v||b==u||a==b) return ;
    if(s[a]>s[b]) dsu[b]=a,s[a]+=s[b],s[b]=0;
    else dsu[a]=b,s[b]+=s[a],s[a]=0;
   /* bug(u);
    bug(a);
    bug(s[a]);
    bug(v);
    bug(b);
    bug(s[b]); */
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) dsu[i]=i,s[i]=1;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        uniondsu(x,y);
    }
    for(int i=1;i<=n;i++) cout<<s[finddsu(i)]-1<<" ";
    return 0;
}



