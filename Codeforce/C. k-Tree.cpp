#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
ll dp[105][105]={0},n,k,Ti=0,mod=1e9+7,d;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k>>d;
	dp[0][0]=1;
	for(int i=0;i<=n;i++){
        for(int j=1;j<=k;j++){
            for(int used=0;used<=1;used++){
                if(j+i<=n){
                    if(j<d) dp[j+i][used]+=dp[i][used];
                    else dp[j+i][1]+=dp[i][used];
                    dp[j+i][0]%=mod;
                    dp[j+i][1]%=mod;
                }
            }
        }
	}
	Ti=dp[n][1];
	cout<<Ti<<endl;
	return 0;
}
