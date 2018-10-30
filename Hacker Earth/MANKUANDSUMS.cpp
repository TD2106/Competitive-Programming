#include <iostream>
#include <cstring>
using namespace std;
int main (){
	int tc,arr[10010],sum[10010],n,ans;
	cin>>tc;
	while(tc--){
		ans=0;
		memset(arr,0,sizeof(arr));
		memset(sum,0,sizeof(sum));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			sum[i]=arr[i];
			for(int j=i-2;j>0;j--)sum[i]=max(sum[i],sum[j]+arr[i]);
			ans=max(ans,sum[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
