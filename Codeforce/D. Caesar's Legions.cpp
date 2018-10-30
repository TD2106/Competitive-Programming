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
ll dp[105][105][15][2]={0},n1,n2,k1,k2,Ti=0,mod=1e8;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n1>>n2>>k1>>k2;
	dp[0][0][0][0]=1;
	dp[0][0][0][1]=1;
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            for(int k=0;k<=10;k++){
                for(int p=1;p<=10;p++){
                    if(p+i<=n1){
                        if(p<=k1) dp[p+i][j][p][0]+=dp[i][j][k][1],dp[p+i][j][p][0]%=mod;
                    }
                    if(p+j<=n2){
                        if(p<=k2) dp[i][j+p][p][1]+=dp[i][j][k][0],dp[i][j+p][p][1]%=mod;
                    }
                }
            }
        }
    }
    for(int k=1;k<=10;k++) Ti=(Ti+dp[n1][n2][k][0]+dp[n1][n2][k][1])%mod;
    cout<<Ti<<endl;
	return 0;
}
