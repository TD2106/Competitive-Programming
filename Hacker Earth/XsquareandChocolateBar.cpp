#include <iostream>
#include <cstring>
using namespace std;
int dp[1000000];
int main (){
	int tc,ans;
	string s;
	cin>>tc;
	while(tc--){
		ans=0;
		cin>>s;
		memset(dp,0,sizeof(dp));
		for(int i=2;i<s.size();i++){
			if(!(s[i-2]==s[i-1]&&s[i-2]==s[i]))
			dp[i]++;
			if(i>2&&dp[i]>0)
			dp[i]=dp[i]+dp[i-3];
			ans=max(ans,dp[i]);
		}
		cout<<s.size()-ans*3<<endl;
	}
	return 0;
}
