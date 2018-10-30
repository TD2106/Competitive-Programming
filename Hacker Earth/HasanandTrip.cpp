#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define F first
#define S second
using namespace std;
typedef long long int ll;
int n,lastCity[3005]={0};
pair< pair<double,double>,double > city[3005];
double Ti=0,dp[2][3005]={0},t1,t2;
double distance(pair<double,double> a,pair<double,double> b){
    return sqrt((a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S));
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>city[i].F.F>>city[i].F.S>>city[i].S;
    for(int i=1;i<n;i++) dp[1][i]=dp[0][i]=-2e9;
    dp[0][0]=dp[1][0]=city[0].S;
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            t1=city[i].S+dp[0][j]-distance(city[i].F,city[j].F);
            t2=city[i].S+dp[1][j]-distance(city[i].F,city[lastCity[j]].F);
            if(t1>dp[0][i]||t2>dp[0][i]) dp[0][i]=max(t1,t2);
            t1=dp[0][j];
            t2=dp[1][j];
            if(t1>dp[1][i]||t2>dp[1][i]){
                if(t1>t2) dp[1][i] = t1,lastCity[i]=j;
                else dp[1][i]=t2,lastCity[i]=lastCity[j];
            }
        }
       // cout<<dp[0][i]<<" "<<dp[1][i]<<endl;
    }
    Ti=dp[0][n-1];
    cout<<fixed<<setprecision(6)<<Ti<<endl;
    return 0;
}
