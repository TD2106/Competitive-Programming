#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
int main (){
	ll tc,n,dp[210],ans;
	pair<ll,ll> arr[210];
	cin>>tc;
	while(tc--){
		ans=0;
		cin>>n;
		memset(dp,0,sizeof(dp));
		memset(arr,0,sizeof(arr));
		for(int i=1;i<=n;i++){
			cin>>arr[i].first>>arr[i].second;
		}
		sort(arr+1,arr+1+n);
		for(int i=1;i<=n;i++){
			dp[i]=arr[i].second;
			for(int j=i-1;j>0;j--){
				if(arr[j].first<arr[i].first&&arr[j].second<arr[i].second)
				dp[i]=max(dp[i],dp[j]+arr[i].second);
			}
			ans=max(ans,dp[i]);
		}
		cout<<ans<<endl;
	}
}
