#include <iostream>
using namespace std;
int main (){
	// the idea for this problem is dp. Basically we have to find the 
	//minimum paper spent at each steps and continue to calculate forward.
	int dp[120]={0},tc,n;
	for(int i=1;i<=9;i++) dp[i]=-1;
	dp[10]=dp[12]=1;
	dp[11]=-1;
	for(int i=13;i<=115;i++){
		if(dp[i-10]!=-1&&dp[i-12]!=-1)
		dp[i]=min(dp[i-10]+1,dp[i-12]+1);
		else if(dp[i-10]==-1&&dp[i-12]==-1)
		dp[i]=-1;
		else if (dp[i-10]==-1&&dp[i-12]!=-1)
		dp[i]=dp[i-12]+1;
		else
		dp[i]=dp[i-10]+1;
	}
	cin>>tc;
	while(tc--){
		cin>>n;
		cout<<dp[n]<<endl;
	}
	return 0;
}
