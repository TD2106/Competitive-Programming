#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
int tc,n,a,b,w,dis[100001];
bool visited[100001];
vector< vector< pair<int,int> > > adj;
queue<int> line;
int bfs(){
	while(!line.empty()){
		int u=line.front();
		line.pop();
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i].first;
			//cout<<v<<endl;
			//cout<<u<<" "<<v<<endl;
			if(!visited[v]){
				line.push(v);
				visited[v]=1;
				dis[v]=dis[u]+adj[u][i].second;
			}
		}
	}
	int ans=0,maxdis=0;
	for(int i=0;i<=n;i++){
		if(dis[i]>maxdis){
			maxdis=dis[i];
			ans=i;
		}
	}
	return ans;
}
int main (){
	cin>>tc;
	while(tc--){
		cin>>n;
		adj.clear();
		vector< pair<int,int> > temp;
		adj.assign(n+1,temp);
		//cout<<"YES";
		for(int i=0;i<n-1;i++){
			cin>>a>>b>>w;
			adj[a].push_back(make_pair(b,w));
			adj[b].push_back(make_pair(a,w));
		}
		//cout<<"YES\n";
		memset(dis,0,sizeof(dis));
		memset(visited,0,sizeof(visited));
		line.push(1);
		visited[1]=1;
		int far=bfs();
		//cout<<far<<endl;
		//cout<<"YES"<<endl;
		memset(dis,0,sizeof(dis));
		memset(visited,0,sizeof(visited));
		line.push(far);
		visited[far]=far;
		far=bfs();
		int cost;
		if(dis[far]<=100) cost=0;
		else if(dis[far]>10000) cost=10000;
		else if(dis[far]>1000) cost=1000;
		else if(dis[far]>100) cost=100;
		cout<<cost<<" "<<dis[far]<<endl;
	}
	return 0;
}
