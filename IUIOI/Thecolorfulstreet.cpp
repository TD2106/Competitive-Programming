#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;

int main(){
    int tc,n,color[3],dp[2005][3];
    cin>>tc;
    while(tc--){
        cin>>n;
        reset(dp);
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++) cin>>color[j];
            for(int j=0;j<3;j++){
                if(j==0) dp[i][j]=min(dp[i-1][1]+color[j],dp[i-1][2]+color[j]);
                if(j==1) dp[i][j]=min(dp[i-1][0]+color[j],dp[i-1][2]+color[j]);
                if(j==2) dp[i][j]=min(dp[i-1][1]+color[j],dp[i-1][0]+color[j]);
            }
        }
        cout<<min(dp[n][0],min(dp[n][1],dp[n][2]))<<endl;
    }
	return 0;
}
