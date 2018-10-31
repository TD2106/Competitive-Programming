#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll dp[105][105][105],p[105][105],a[105],n,k,m,Ti=1e15;
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>p[i][j];
    }
    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
            for(int l=1;l<=100;l++)
            dp[i][j][l]=1e15;
    if(a[1]==0){
        for(int i=1;i<=m;i++) dp[1][i][1]=p[1][i];
    }
    else dp[1][a[1]][1]=0;
    for(int i=2;i<=n;i++){
        if(a[i]==0){
            for(int j=1;j<=m;j++){
                for(int l=1;l<=k;l++){
                    if(dp[i-1][j][l]!=1e15){
                        for(int o=1;o<=m;o++){
                            if(o==j) dp[i][o][l]=min(dp[i][o][l],dp[i-1][j][l]+p[i][o]);
                            else dp[i][o][l+1]=min(dp[i][o][l+1],dp[i-1][j][l]+p[i][o]);
                        }
                    }
                }
            }
        }
        else{
            for(int j=1;j<=m;j++){
                for(int l=1;l<=k;l++){
                    if(dp[i-1][j][l]!=1e15){
                        if(a[i]==j) dp[i][a[i]][l]=min(dp[i][a[i]][l],dp[i-1][j][l]);
                        else dp[i][a[i]][l+1]=min(dp[i][a[i]][l+1],dp[i-1][j][l]);
                    }
                }
            }
        }
    }
    for(int i=1;i<=m;i++) Ti=min(Ti,dp[n][i][k]);
    if(Ti==1e15) cout<<-1<<endl;
    else cout<<Ti<<endl;
	return 0;
}
