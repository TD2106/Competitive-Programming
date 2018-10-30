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
int dp[105][3]={0},n,a[105],Ti=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n) cin>>a[i];
    up(i,1,n){
        dp[i][0]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
        if(a[i]==0) dp[i][1]=dp[i][2]=-1e9;
        else if(a[i]==1){
            dp[i][1]=max(dp[i-1][0],dp[i-1][2])+1;
            dp[i][2]=-1e9;
        }
        else if(a[i]==2){
            dp[i][2]=max(dp[i-1][0],dp[i-1][1])+1;
            dp[i][1]=-1e9;
        }
        else{
            dp[i][1]=max(dp[i-1][0],dp[i-1][2])+1;
            dp[i][2]=max(dp[i-1][0],dp[i-1][1])+1;
        }
    }
    Ti=max(max(dp[n][0],dp[n][1]),dp[n][2]);
    Ti=n-Ti;
    cout<<Ti<<endl;
    return 0;
}
