#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    string s;
    int dp[205]={0},Ti=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        dp[i]=1;
        for(int j=i-1;j>=0;j--){
            if(s[j]<=s[i]) dp[i]=max(dp[i],1+dp[j]);
        }
        Ti=max(Ti,dp[i]);
    }
    cout<<Ti<<endl;
	return 0;
}
