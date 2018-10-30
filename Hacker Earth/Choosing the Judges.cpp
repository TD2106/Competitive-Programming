#include <iostream>
#include <cstring>
using namespace std;
int main (){
	long long tc,arr[10010],dp[10010],n,ans;
	cin>>tc;
	for(int ca=1;ca<=tc;ca++){
		cin>>n;
		ans=0;
		memset(arr,0,sizeof(arr));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			dp[i]=arr[i];
			for(int j=i-2;j>0;j--) dp[i]=max(dp[i],dp[j]+arr[i]);
			ans=max(dp[i],ans);
		}
		cout<<"Case "<<ca<<": "<<ans<<endl;
	}
	return 0;
}
