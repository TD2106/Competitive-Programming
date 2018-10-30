#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
vector< vector<int> > data;
queue<int> linking;
int tc,n,m,u,v,dis[10001];
bool visit[10001];
int main (){
	cin>>tc;
	while(tc--){
		cin>>n>>m;
		vector<int> temp;
		data.clear();
		for(int i=0;i<=n;i++) data.push_back(temp);
		for(int i=0;i<m;i++){
			cin>>u>>v;
			if(u==v) continue;
			data[u].push_back(v);
			data[v].push_back(u);
		}
		while(!linking.empty()) linking.pop();
		linking.push(1);
		for(int i=1;i<=10000;i++) dis[i]=2000000000;
		dis[1]=0;
		memset(visit,0,sizeof(visit));
		while(!linking.empty()){
			int x=linking.front();
			visit[x]=1;
			linking.pop();
			for(int i=0;i<data[x].size();i++){
				dis[data[x][i]]=min(dis[data[x][i]],dis[x]+1);
				if(!visit[data[x][i]])
				linking.push(data[x][i]);
			}
			
		}
		cout<<dis[n]<<endl;
	}
	return 0;
}
