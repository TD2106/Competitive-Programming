#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
int a[21][3],dp[21][3],Ti,n,tc;
int main(){
    cin>>tc;
    while(tc--){
        reset(a);
        reset(dp);
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++) cin>>a[i][j];
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                if(i==1) dp[i][j]=a[i][j];
                else dp[i][j]=a[i][j]+min(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3]);
            }
        }
        Ti=1e9;
        for(int i=0;i<3;i++) Ti=min(Ti,dp[n][i]);
        cout<<Ti<<endl;
    }
    return 0;
}
