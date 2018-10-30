#include <iostream>
#include <cstring>
using namespace std;
int arr[3][100010],dp[3][100010],tc,n,ans;
int main (){
	cin>>tc;
	while(tc--){
		ans=1000000000;
		memset(dp,0,sizeof(dp));
		memset(arr,0,sizeof(arr));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[0][i]>>arr[1][i]>>arr[2][i];
			dp[0][i]=min(arr[0][i]+dp[1][i-1],arr[0][i]+dp[2][i-1]);
			dp[1][i]=min(arr[1][i]+dp[0][i-1],arr[1][i]+dp[2][i-1]);
			dp[2][i]=min(arr[2][i]+dp[0][i-1],arr[2][i]+dp[1][i-1]);
		}
		for(int i=0;i<3;i++) ans=min(ans,dp[i][n]);
		cout<<ans<<endl;
	}
}
