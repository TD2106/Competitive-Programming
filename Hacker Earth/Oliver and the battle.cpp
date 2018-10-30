#include <iostream>
#include <cstring>
using namespace std;
bool matrix[1002][1002];
int dfs(int r,int c){
	if(!matrix[r][c]){
		return 0;
	}
	else{
		matrix[r][c]=0;
		return 1+dfs(r+1,c)+dfs(r-1,c)+dfs(r,c-1)+dfs(r,c+1)+dfs(r+1,c+1)+dfs(r-1,c+1)+dfs(r+1,c-1)+dfs(r-1,c-1);
	}
}
int main (){
	int troops,tc,num,maxNum,row,column;
	cin>>tc;
	while(tc--){
		maxNum=0;
		troops=0;
		cin>>row>>column;
		memset(matrix,0,sizeof(matrix));
		for(int i=1;i<=row;i++){
			for(int j=1;j<=column;j++){
				cin>>matrix[i][j];
			}
		}
		for(int i=1;i<=row;i++){
			for(int j=1;j<=column;j++){
				if(matrix[i][j]){
					troops++;
					num=dfs(i,j);
					maxNum=max(num,maxNum);
				}
			}
		}
		cout<<troops<<" "<<maxNum<<endl;
	}
	return 0;
}
