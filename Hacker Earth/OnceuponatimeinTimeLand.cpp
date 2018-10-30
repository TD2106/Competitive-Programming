#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int main (){
	ll n,tc,arr[10005],sum[10005],k;
	cin>>tc;
	while(tc--){
		cin>>n>>k;
		memset(arr,0,sizeof(arr));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++) cin>>arr[i];
		for(int i=1;i<=k+1;i++){
			sum[i]=max(arr[i],sum[i-1]);
		}
		for(int i=k+2;i<=n;i++){
			sum[i]=max(arr[i]+sum[i-(k+1)],sum[i-1]);
		}
		cout<<sum[n]<<endl;
	}
	return 0;
}
