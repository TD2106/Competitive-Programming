#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
string rev(string s){
	string re;
	for(int i=s.size()-1;i>=0;i--) re+=s[i];
	return re;
}
string s,t1,t2;
vector<string> str;
ll n,c[100005]={0},dp[100005][2]={0};
int main (){
	cin>>n;
	for(int i=0;i<n;i++) cin>>c[i];
	for(int i=0;i<n;i++) cin>>s,str.push_back(s);
	for(int i=0;i<=n;i++) dp[i][0]=dp[i][1]=200000000000000;
	dp[0][0]=0;
	dp[0][1]=c[0];
	for(int i=1;i<n;i++){
		t1=rev(str[i-1]);
		t2=rev(str[i]);
		if(str[i]>=str[i-1])
		dp[i][0]=min(dp[i-1][0],dp[i][0]);
		if(str[i]>=t1)
		dp[i][0]=min(dp[i-1][1],dp[i][0]);
		if(t2>=str[i-1])
		dp[i][1]=min(dp[i-1][0]+c[i],dp[i][1]);
		if(t2>=t1)
		dp[i][1]=min(dp[i-1][1]+c[i],dp[i][1]);
	}
	if(dp[n-1][0]==200000000000000&&dp[n-1][1]==200000000000000) cout<<-1<<endl;
	else cout<<min(dp[n-1][0],dp[n-1][1])<<endl;
	return 0;
}
