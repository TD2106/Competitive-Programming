#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int main (){
	bool stage[1005][1005]={0};
	ll m,n,ans=0,row[1005],col[1005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>stage[i][j];
	}
	for(int i=1;i<=n;i++){
		memset(col,0,sizeof(col));
		for(int j=1;j<=m;j++){
			if(stage[i][j]) col[j]=1;
			else{
				col[j]=col[j-1];
				ans+=col[j];
			}
		}
		memset(col,0,sizeof(col));
		for(int j=m;j>=1;j--){
			if(stage[i][j]) col[j]=1;
			else{
				col[j]=col[j+1];
				ans+=col[j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		memset(row,0,sizeof(row));
		for(int j=1;j<=n;j++){
			if(stage[j][i]) row[j]=1;
			else{
				row[j]=row[j-1];
				ans+=row[j];
			}
		}
		memset(row,0,sizeof(row));
		for(int j=n;j>=1;j--){
			if(stage[j][i]) row[j]=1;
			else{
				row[j]=row[j+1];
				ans+=row[j];
			}
		}
	}
	cout<<ans<<endl;
}
