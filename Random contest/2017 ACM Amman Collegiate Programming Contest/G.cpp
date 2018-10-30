#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
ll tc,n,Ti=0;
ll lcm[2005][2005],dp[2005]={0},a[2005];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>tc;
	while(tc--){
        cin>>n;
        Ti=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            dp[i]=dp[i-1]+a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(i==j) lcm[i][j]=a[i],Ti++;
                else{
                    if(dp[n]*__gcd(lcm[i][j-1],a[j])/a[j]<a[j]) break;
                    lcm[i][j]=lcm[i][j-1]*a[j]/__gcd(lcm[i][j-1],a[j]);
                    if((dp[j]-dp[i-1])%lcm[i][j]==0) Ti++;
                }
            }
        }
        cout<<Ti<<endl;
	}
	return 0;
}
