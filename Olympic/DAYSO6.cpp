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
ll dp[4][100005],Ti=-1e18,n,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n){
        cin>>t;
        up(j,1,3) dp[j][i]=j*t;
    }
    up(i,2,n) dp[1][i]=max(dp[1][i-1],dp[1][i]);
    down(i,n-1,1) dp[3][i]=max(dp[3][i+1],dp[3][i]);
    up(i,2,n-1) Ti=max(Ti,dp[1][i-1]+dp[2][i]+dp[3][i+1]);
    cout<<Ti<<endl;
    return 0;
}
