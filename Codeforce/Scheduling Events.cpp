#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
int sum[100005]={0},t,dp[100005][105]={0},n,k,l[105];
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    up(i,1,n) cin>>t,sum[i]=sum[i-1]+t;
    up(i,1,k) cin>>l[i];
    up(i,0,n){
        up(j,1,k) dp[i][j]=2e9;
    }
    up(i,1,n){
        up(j,1,k){
            if(i>=l[j]){
                dp[i][j]=min(dp[i][j],dp[i-l[j]][j-1]+(sum[i]-sum[i-l[j]]));
            }
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
        }
    }
    if(dp[n][k]==2e9) cout<<-1<<endl;
    else cout<<dp[n][k]<<endl;
    return 0;
}
