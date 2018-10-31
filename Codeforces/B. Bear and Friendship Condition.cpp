#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define M 150005
using namespace std;
typedef long long int ll;
vector< vector<int> > adj;
ll d[M],s[M]={0},c[M]={0},n,m,x,y;
ll fn(ll x){
    if(x==d[x]) return x;
    else return d[x]=fn(d[x]);
}
void un(ll u ,ll v){
    u=fn(u);
    v=fn(v);
    if(u==v) return;
    else{
        if(s[u]>=s[v]) swap(u,v);
        d[u]=v;
        s[v]+=s[u];
        s[u]=0;
    }
}
int main(){
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=1;i<=n;i++) d[i]=i,s[i]=1;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        un(x,y);
    }
    for(int i=1;i<=n;i++){
        c[fn(i)]+=(ll)(adj[i].size());
    }
    for(int i=1;i<=n;i++){
        if(c[i]!=(s[i]-1)*s[i]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
