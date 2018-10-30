#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define mod 1000000007
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
int n,m,lastVis[100005]={0},counter=0,u,v,component[100005]={0};
vector<vi> adj,revAdj,scc;
vi sortedList,Ti;
set<int> cnt;
void dfs(int x){
    lastVis[x]=1;
    for(int i=0;i<adj[x].size();i++){
        if(!lastVis[adj[x][i]]){
            dfs(adj[x][i]);
        }
    }
    sortedList.push_back(x);
}
void kosaraju(int x,int group){
    scc[group].push_back(x);
    lastVis[x]=1;
    for(int i=0;i<revAdj[x].size();i++){
        if(!lastVis[revAdj[x][i]]){
            kosaraju(revAdj[x][i],group);
        }
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	adj.resize(n+1);
	revAdj.resize(n+1);
	scc.resize(n+1);
	while(m--){
        cin>>u>>v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
        if(!lastVis[i]) dfs(i);
	}
	reset(lastVis);
	counter=0;
	reverse(sortedList.begin(),sortedList.end());
	for(int i=0;i<sortedList.size();i++){
        if(!lastVis[sortedList[i]]){
            kosaraju(sortedList[i],++counter);
        }
	}
	for(int i=1;i<=counter;i++){
        for(int j=0;j<scc[i].size();j++){
            component[scc[i][j]]=i;
        }
	}
	for(int i=1;i<=counter;i++){
        cnt.clear();
        for(int j=0;j<scc[i].size();j++){
            for(int k=0;k<adj[scc[i][j]].size();k++) cnt.insert(component[adj[scc[i][j]][k]]);
        }
        if(cnt.size()==counter){
            for(int j=0;j<scc[i].size();j++) Ti.push_back(scc[i][j]);
        }
	}
	cout<<Ti.size()<<endl;
	for(int i=0;i<Ti.size();i++) cout<<Ti[i]<<" ";
	return 0;
}

