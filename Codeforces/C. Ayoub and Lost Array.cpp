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
ll MOD = 1e9 + 7;
ll n, l, r, ans = 0, dp[200005][3] = {0}, cnt[3] = {0};
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> l >> r;
    cnt[0] = cnt[1] = cnt[2] = (r - l + 1) / 3;
    up(i, 0, (r - l  + 1) % 3 - 1){
        cnt[(l + i) % 3]++;
    }
    dp[1][0] = cnt[0];
    dp[1][1] = cnt[1];
    dp[1][2] = cnt[2];
    up(i, 1, n - 1){
        up(j, 0, 2){
            up(k, 0, 2){
                dp[i + 1][(j + k) % 3] += dp[i][j] * cnt[k];
                dp[i + 1][(j + k) % 3] %= MOD;
            }
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}
