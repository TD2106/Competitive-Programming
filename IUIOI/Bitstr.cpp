#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;
ll n,dp[100005]={0},k,mod=1e9+7,Ti;
int main(){
    cin>>n>>k;
    dp[k]=1;
    for(int i=k;i<=n;i++){
        dp[i]+=dp[i-1]%mod;
        if(i>=k) dp[i]+=dp[i-k]%mod;
        dp[i]%=mod;
    }
    cout<<dp[n]<<endl;
    return 0;
}
