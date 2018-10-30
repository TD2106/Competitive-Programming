#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define pb push_back
using namespace std;
typedef long long int ll;
int d[100005],s[100005]={0},n,m,Ti=0,connect[100005]={0},x,y;
vector< vector<int> > adj;
int fn(int x){
    if(d[x]==x) return x;
    else return d[x]=fn(d[x]);
}
void un(int u,int v){
    u=fn(u);
    v=fn(v);
    if(u==v) return;
    if(s[u]>=s[v]) d[v]=u,s[u]+=s[v],s[v]=0;
    else d[u]=v,s[v]+=s[u],s[u]=0;
}
int main(){
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=1;i<=n;i++) d[i]=i,s[i]=1;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        un(x,y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(int i=1;i<=n;i++){
        connect[fn(i)]+=(int)adj[i].size();
        //cout<<i<<" "<<adj[i].size()<<" "<<fn(i)<<" "<<connect[fn(i)]<<endl;
    }
    for(int i=1;i<=n;i++) if(connect[i]) connect[i]/=2;
    for(int i=1;i<=n;i++){
        //cout<<s[i]<<" "<<connect[i]<<endl;
        if(s[i]==1) Ti++;
        else if(s[i]!=0&&connect[i]<s[i]) Ti++;
    }
    cout<<Ti<<endl;
    return 0;
}
