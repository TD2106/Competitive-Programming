#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<int> sieve (){
	vector<int> prime;
	bool marking[5010]={0};
	for(int i=2;i<=5000;i++){
		if(!marking[i]){
			prime.push_back(i);
			for(int j=i*i;j<=5000;j+=i) marking[j]=1;
		}
	}
	return prime;
}
int main (){
	vector<int> prime=sieve();
	int arr[5010]={0},sum[5010]={0},dp[5010]={0},n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		sum[i]=sum[i-1]+arr[i];
		dp[i]=dp[i-1];
		for(int j=0;j<prime.size()&&prime[j]<=i;j++){
			int temp=i-prime[j]-1;
			if(temp==-1) dp[i]=max(dp[i],sum[i]);
			else {
				dp[i]=max(dp[i],dp[temp]+sum[i]-sum[temp+1]);
			}
		}
	}
	cout<<dp[n]<<endl;
}
