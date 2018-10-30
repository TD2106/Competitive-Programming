#include <iostream>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
ll k,n,tc,arr[1010];
ll fastpow(ll base,ll exponent){
	if(exponent==0)
	return 1;
	else if(exponent==1){
		return base%k;
	}
	else{
		if(exponent%2){
			return (base%k*fastpow(base,exponent-1)%k)%k;
		}
		else{
			return (fastpow(base,exponent/2)%k*fastpow(base,exponent/2)%k)%k;
		}
	}
}
int main (){
	cin>>tc;
	while(tc--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>arr[i];
		for(int i=1;i<=n-1;i++){
			ll temp=fastpow(arr[i],arr[i+1]);
			arr[i+1]=temp;
		}
		cout<<arr[n]<<endl;
	}
	return 0;
}
