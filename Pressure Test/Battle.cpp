#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
int testCase,n,m,u,v,s,t,Ti,c[405][405],f[405][405],trace[405],minn;
void bfs(){
    queue<int> q;
    q.push(s);
    reset(trace);
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int i=1;i<=(n+m+1);i++){
            if(trace[i]==0&&(c[u][i]>f[u][i])){
                trace[i]=u;
                q.push(i);
                //cout<<u<<" "<<i<<endl;
            }
        }
    }
}
void dfs(int source,int x){
    trace[x]=source;
    if(trace[t]!=0) return;
    for(int i=1;i<=n+m+1;i++){
        if(trace[i]==0&&c[x][i]>f[x][i]){
            dfs(x,i);
            if(trace[t]!=0) return;
        }
    }
}
void flow(){
    v=t;
    minn=1e9;
    while(v!=s){
        u=trace[v];
        minn=min(minn,c[u][v]-f[u][v]);
        v=u;
    }
    v=t;
    while(v!=s){
        u=trace[v];
        f[u][v]+=minn;
        f[v][u]-=minn;
        v=u;
    }
    Ti+=minn;
}
void fordFulkerson(){
    Ti=0;
    while(1){
        reset(trace);
        dfs(0,0);
        if(trace[t]==0) break;
        flow();
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	fr("BATTLE.INP");
	fw("BATTLE.OUT");
    cin>>testCase;
    for(int tc=1;tc<=testCase;tc++){
        cin>>m>>n;
        reset(c);
        reset(f);
        s=0,t=n+m+1;
        for(int i=1;i<=n;i++) c[s][i]=1;
        for(int i=n+1;i<=n+m;i++) c[i][t]=1;
        for(int i=1;i<=n;i++){
            cin>>u;
            while(u--){
                cin>>v;
                v+=n;
                c[i][v]=1;
            }
        }
        fordFulkerson();
        cout<<"Battle "<<tc<<": "<<Ti<<endl;
    }
	return 0;
}
