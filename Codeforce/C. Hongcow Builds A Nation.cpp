#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
int vertex,edge,n,m,k,c,u,v,ans=0,cnt=0,start;
bool visited[1005]={0},gov[1005]={0},check[1005][1005]={0};
queue<int> q;
int main (){
	cin>>n>>m>>k;
	vector< vector<int> > e(n+1);
	for(int i=0;i<k;i++) cin>>c,gov[c]=1;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(gov[i]){
			visited[i]=1;
			q.push(i);
			vertex=1;
			edge=0;
			while(!q.empty()){
				u=q.front();
				q.pop();
				for(int j=0;j<e[u].size();j++){
					if(!visited[e[u][j]]){
						visited[e[u][j]]=1;
						vertex++;
						q.push(e[u][j]);
					}
					if(!check[u][e[u][j]]){
						check[u][e[u][j]]=1;
						check[e[u][j]][u]=1;
						edge++;
					}
				}
			}
			//cout<<vertex<<" "<<edge<<endl;
			cnt=max(cnt,vertex);
			if(edge!=(vertex-1)*vertex/2) ans+=(vertex-1)*vertex/2-edge;
		}
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			visited[i]=1;
			q.push(i);
			vertex=1;
			edge=0;
			while(!q.empty()){
				u=q.front();
				q.pop();
				for(int j=0;j<e[u].size();j++){
					if(!visited[e[u][j]]){
						visited[e[u][j]]=1;
						vertex++;
						q.push(e[u][j]);
					}
					if(!check[u][e[u][j]]){
						check[u][e[u][j]]=1;
						check[e[u][j]][u]=1;
						edge++;
					}
				}
			}
			ans+=vertex*cnt;
			cnt+=vertex;
			if(edge!=(vertex-1)*vertex/2) ans+=(vertex-1)*vertex/2-edge;
		}
	}
	cout<<ans<<endl;
}
