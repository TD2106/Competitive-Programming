#include <iostream>
using namespace std;
int n,cnt=0,ans=1000000000,r,c;
char jungle[40][40]={0};
bool visited[40][40]={0};
void dfs(int row,int column){
	if(visited[row][column])
	return;
	visited[row][column]=1;
	if(jungle[row][column]=='T'){
		return;
	}
	else if(jungle[row][column]=='E'){
		ans=min(ans,cnt);
		visited[row][column]=0;
		return;
	}
	else{
		cnt++;
		dfs(row+1,column);
		cnt--;
		cnt++;
		dfs(row-1,column);
		cnt--;
		cnt++;
		dfs(row,column-1);
		cnt--;
		cnt++;
		dfs(row,column+1);
		cnt--;	
		visited[row][column]=0;
	}
}
int main (){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>jungle[i][j];
			if(jungle[i][j]=='S'){
				r=i;
				c=j;
			}
		}
	}
	for(int i=0;i<40;i++){
		for(int j=0;j<=40;j++){
			if(jungle[i][j]==0)
			jungle[i][j]='T';
		}
	}
	dfs(r,c);
	cout<<ans<<endl;
	return 0;
}
