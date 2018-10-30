#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<int> primatic;
void sieve(){
	bool mark[10010]={0};
	for(int i=2;i<=10000;i++){
		if(!mark[i]){
			primatic.push_back(i);
			if(pow(i,i)<=10000)
			primatic.push_back(pow(i,i));
			for(int j=i*i;j<=10000;j+=i)
			mark[j]=1;
		}
	}
	sort(primatic.begin(),primatic.end());
}
///////The idea for this one is to get all the primatic number first. Then you use dp to calculate how
///////each n is sumed up. This is done by calculate from the smaller state to bigger state
int main (){
	//freopen("Prime Numbers Again.txt","r",stdin);
	int tc,n,dp[10010]={0};
	for(int i=1;i<=10000;i++) dp[i]=100000;
	sieve();
	//for(int j=0;j<primatic.size();j++)
	//cout<<primatic[j]<<endl;
	for(int i=1;i<=10000;i++){
		for(int j=0;j<primatic.size()&&primatic[j]<=i;j++){
			if(dp[i-primatic[j]]!=10000){
				dp[i]=min(dp[i],1+dp[i-primatic[j]]);
			}
		}
	}
	cin>>tc;
	while(tc--){
		cin>>n;
		cout<<dp[n]<<endl;
	}
	return 0;
}
