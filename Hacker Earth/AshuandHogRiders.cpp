#include <iostream>
using namespace std;
bool graph[1010][1010]={0},first;
int sum,ans=0;
void dfs(int row,int col){
	if(!graph[row][col])
	return;
	else{
		graph[row][col]=0;
		sum++;
		dfs(row+1,col);
		dfs(row-1,col);
		dfs(row,col+1);
		dfs(row,col-1);
	}
}
int main (){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cin>>graph[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum=0;
			dfs(i,j);
			ans=max(sum,ans);
		}
	}
	cout<<ans;
}
