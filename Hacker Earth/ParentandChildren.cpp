#include <iostream>
#include <vector>
using namespace std;
vector< vector<int> > people;
int dis[1000010]={0};
vector<int> queue;
bool visited[1000010]={0};
void bfs(){
	while(!queue.empty()){
		int start=queue[0];
		queue.erase(queue.begin());
		visited[start]=1;
		for(int i=0;i<people[start].size();i++){
			if(!visited[people[start][i]]){
				queue.push_back(people[start][i]);
				dis[people[start][i]]=dis[start]+1;
			}
		}
	}
}
int main (){
	int n,u,v,q;
	cin>>n;
	vector<int> temp;
	for(int i=0;i<=n;i++) people.push_back(temp);
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		people[u].push_back(v);
		people[v].push_back(u);
	}
	queue.push_back(1);
	bfs();
	cin>>q;
	while(q--){
		cin>>u>>v;
		if(dis[u]<dis[v]){
			cout<<u<<" parent of "<<v<<endl;
		}
		else {
			cout<<v<<" parent of "<<u<<endl;
		}
	}
	return 0;
}
