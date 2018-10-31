#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define F first
#define S second
using namespace std;
typedef long long int ll;
int n,m,Ti=0,l[20]={0},r[20]={0},dp[2][20]={0},last=0,temp;
string light;
int main(){
    cin>>n>>m;
    for(int i=n;i>=1;i--){
        cin>>light;
        for(int j=0;j<light.size();j++){
            if(light[j]=='1'){
                if(l[i]==0) l[i]=r[i]=j+1;
                else r[i]=j+1;
                last=max(last,i);
            }
        }
    }
    if(last==0){
        cout<<0<<endl;
        return 0;
    }
    if(last==1){
        cout<<r[1]-1<<endl;
        return 0;
    }
    if(l[1]) dp[0][1]=2*r[1]-2;
    else dp[0][1]=0;
    dp[1][1]=m+1;
    //cout<<dp[0][1]<<" "<<dp[1][1]<<endl;
    for(int i=2;i<=last;i++){
        if(i==last){
            temp=m+2-l[i]+1;
            Ti=min(dp[0][i-1]+r[i],dp[1][i-1]+temp);
        }
        else{
            if(l[i]==0){
                dp[0][i]=min(dp[0][i-1]+1,dp[1][i-1]+m+2);
                dp[1][i]=min(dp[1][i-1]+1,dp[0][i-1]+m+2);
            }
            else{
                temp=m+2-l[i]+1;
                dp[0][i]=min(dp[0][i-1]+2*r[i]-1,dp[1][i-1]+m+2);
                dp[1][i]=min(dp[1][i-1]+(2*temp-1),dp[0][i-1]+m+2);
            }
        }
       // cout<<dp[0][i]<<" "<<dp[1][i]<<endl;
    }
    cout<<Ti<<endl;
    return 0;
}
