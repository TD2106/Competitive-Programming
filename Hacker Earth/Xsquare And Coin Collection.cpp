#include <iostream>
#include <cstring>
using namespace std;
int main (){
	long long arr[100010],tc,n,k,ans,dp[100010];
	cin>>tc;
	while(tc--){
		ans=0;
		memset(arr,0,sizeof(arr));
		memset(dp,0,sizeof(dp));
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			if(arr[i]>k)
			dp[i]=0;
			else dp[i]=arr[i]+dp[i-1];
			ans=max(dp[i],ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}
