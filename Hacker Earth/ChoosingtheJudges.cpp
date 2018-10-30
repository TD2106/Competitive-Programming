#include <iostream>
#include <cstring>
using namespace std;
int main (){
	int n,arr[10005],sum[10005],tc,ans,count=0;
	cin>>tc;
	while(tc--){
		cin>>n;
		ans=0;
		memset(sum,0,sizeof(sum));
		memset(arr,0,sizeof(arr));
		for(int i=1;i<=n;i++) cin>>arr[i];
		for(int i=1;i<=n;i++){
			sum[i]=arr[i];
			for(int j=i-2;j>0;j--){
				sum[i]=max(sum[i],arr[i]+sum[j]);
			}
			ans=max(ans,sum[i]);
		}
		cout<<"Case "<<++count<<": "<<ans<<endl;
	}
	return 0;
}
