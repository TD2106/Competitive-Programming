#include <iostream>
#define mod 1000000009;
typedef long long ll;
using namespace std;
ll dp[10000010]={0},tc,n;
int main (){
	dp[1]=1;
	dp[2]=10;
	for(ll i=3;i<=10000000;i++){
		dp[i]+=dp[i-2]+i*i+i*i-(i-1)+i*i-2*(i-1)+i*i-3*(i-1);
		dp[i]%=mod;
	}
	cin>>tc;
	while(tc--){
		cin>>n;
		cout<<dp[n]<<endl;
	}
	return 0;
}
