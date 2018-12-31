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
#define MAX 2005
#define MOD 998244353
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
ll dp[MAX][MAX] = {0}, n, m, k;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    dp[1][0] = m;
    up(i, 2, n){
        up(j, 0, k){
            if(j == 0){
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = (m - 1) * dp[i - 1][j - 1] + dp[i - 1][j];
            }
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}
