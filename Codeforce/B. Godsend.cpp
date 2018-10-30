#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
ll n,temp,dp[1000005]={0},firstOdd=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>temp;
        dp[i]=dp[i-1]+temp;
        if(dp[i]%2) firstOdd=i;
	}
	if((dp[n]%2==1)||(dp[n]%2==0&&firstOdd!=0)){
        cout<<"First\n";
	}
	else cout<<"Second\n";
	return 0;
}
