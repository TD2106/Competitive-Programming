#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
int xr[5005][5005]={0},dp[5005]={0},n,a[5005],t=0,Ti=0,cnt[5005];
bool flag=0;
pair<int,int> lr[5005];
int main(){
    cin>>n;
    for(int i=1;i<=5000;i++) lr[i].first=lr[i].second=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(lr[a[i]].first==0) lr[a[i]].first=lr[a[i]].second=i;
        else lr[a[i]].second=i;
    }
    for(int i=1;i<=n;i++){
        t=0;
        reset(cnt);
        for(int j=i;j<=n;j++){
            if(cnt[a[j]]==0) t^=a[j];
            cnt[a[j]]++;
            xr[i][j]=t;
            //cout<<i<<" "<<j<<" "<<t<<endl;
        }
    }
    for(int i=1;i<=n;i++){
        //bug(i);
        if(lr[a[i]].second==i){
            flag=1;
            for(int j=i-1;j>lr[a[i]].first;j--){
                if(lr[a[j]].first<lr[a[i]].first||lr[a[j]].second>lr[a[i]].second){
                    dp[i]=dp[i-1];
                    flag=0;
                    break;
                }
            }
            if(flag) dp[i]=max(dp[i-1],dp[lr[a[i]].first-1]+xr[lr[a[i]].first][lr[a[i]].second]);
        }
        else dp[i]=dp[i-1];
        //bug(dp[i]);
    }
    for(int i=1;i<=n;i++) Ti=max(Ti,dp[i]);
    Ti=max(Ti,xr[1][n]);
    cout<<Ti<<endl;
	return 0;
}
