#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define F first
#define S second
#define mp make_pair
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
int parent[100005][20]={0},level[100005]={0},n,q,dfsOrder[200005],idx=0,Ti,t,u,v;
pii euler[100005],levelIndex[200005];
vi root;
vector<vi> child;
void dfs(int x){
    level[x]=level[parent[x][0]]+1;
    dfsOrder[++idx]=x;
    euler[x].F=idx;
    for(int t:child[x]) dfs(t);
    dfsOrder[++idx]=x;
    euler[x].S=idx;
}
int walk(int s,int p){
    for(int i=0;i<=19;i++){
        if(p&(1<<i)) s=parent[s][i];
    }
    return s;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin>>n;
    child.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>parent[i][0];
        if(!parent[i][0]){
            root.push_back(i);
        }
        child[parent[i][0]].push_back(i);
    }
    for(int t:root) dfs(t);
    for(int i=1;i<=19;i++){
        for(int j=1;j<=n;j++){
            parent[j][i]=parent[parent[j][i-1]][i-1];
        }
    }
    for(int i=1;i<=2*n;i++) levelIndex[i]={level[dfsOrder[i]],i};
    sort(levelIndex+1,levelIndex+1+2*n);
    cin>>q;
    while(q--){
        cin>>u>>v;
        t=walk(u,v);
        if(t==0) cout<<0<<endl;
        else{
            Ti=lower_bound(levelIndex+1,levelIndex+1+2*n,mp(level[u],euler[t].S))-lower_bound(levelIndex+1,levelIndex+1+2*n,mp(level[u],euler[t].F));
            Ti/=2;
            cout<<Ti-1<<endl;
        }
    }
	return 0;
}
