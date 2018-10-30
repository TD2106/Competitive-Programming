#include <iostream>
#include <cstring>
typedef long long ll;
using namespace std;
int main (){
	ll arr[10005],sum[10005],n,tc;
	cin>>tc;
	while(tc--){
		cin>>n;
		memset(arr,0,sizeof(arr));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)
		cin>>arr[i];
		sum[1]=arr[1];
		for(int i=2;i<=n;i++){
			sum[i]=max(sum[i-1],arr[i]+sum[i-2]);
		}
		cout<<sum[n]<<endl;
	}
}
