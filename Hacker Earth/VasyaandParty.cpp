#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <bitset>
using namespace std;
// The basic idea for this problem is using DFS to continuously look for groups
// when you are done everything is easy
long long ans=1,n,m,u,v,intel[100010]={0};
bool visited[100010]={0};
vector< vector<long long> > rela(100010,vector<long long>(0));
vector<long long> temp;
vector< vector<long long> > group;
void dfs(long long i){
	while(!rela[i].empty()){
		if(visited[rela[i][0]])
		rela[i].erase(rela[i].begin());
		else{
			visited[rela[i][0]]=1;
			temp.push_back(intel[rela[i][0]]);
			dfs(rela[i][0]);
			rela[i].erase(rela[i].begin());
		}
	}
}
bool cmp(long long a,long long b){
	return (a>b);
}
int main (){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>intel[i];
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		if(u==v) continue;
		else{
			rela[u].push_back(v);
			rela[v].push_back(u);
		}
	}
	bitset<100010> marking;
	for(int i=1;i<=n;i++){
		if(rela[i].size()==0) continue;
		else {
			marking.reset();
			temp.clear();
			for(int j=0;j<rela[i].size();j++){
				if(!marking[rela[i][j]]){
					temp.push_back(rela[i][j]);
					marking[rela[i][j]]=1;
				}
			}
			rela[i].clear();
			rela[i]=temp;
		}
	}
	for(int i=1;i<=n;i++){
		if(rela[i].empty()||visited[i]) continue;
		else{
			visited[i]=1;
			temp.clear();
			temp.push_back(intel[i]);
			dfs(i);
			group.push_back(temp);
		}
	}
	for(int i=0;i<group.size();i++){
		sort(group[i].begin(),group[i].end(),cmp);
		if(group[i][group[i].size()-1]==group[i][0])
		ans*=group[i].size()%1000000007;
		else {
			for(int j=1;j<group[i].size();j++){
				if(group[i][j]!=group[i][0]){
					ans*=j%1000000007;
					break;
				}
			}	
		}
		ans%=1000000007;
	}
	cout<<ans%1000000007<<endl;
}
