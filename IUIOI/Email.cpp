#include <bits/stdc++.h>
#define up(i,l,r) for(int i=l;i<=r;i++)
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,dp[205][205]={0},a[205]={0};

int main(){
    fr("EMAIL.INP");
    fw("EMAIL.OUT");
    cin>>n;
    up(i,1,n) cin>>a[i];
    up(i,1,n) dp[i][i]=1;
    up(length,2,n){
        up(i,1,n-length+1){
            int j=i+length-1;
            dp[i][j]=1e9;
            up(k,i,j-1){
                if(a[i]==a[j]||a[k]==a[k+1]) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]-1);
                else dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
//            bug(i);
//            bug(j);
//            bug(dp[i][j]);
        }
    }
    cout<<dp[1][n]<<endl;
	return 0;
}
