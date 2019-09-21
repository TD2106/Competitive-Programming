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
#define M 100005
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
ll n, a[M] = {0}, dp[2][M] = {0}, ans = 0, E = 0, T = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    up(i, 1, n){
        cin >> a[i];
    }
    up(i, 1, n - 1){
        if(i == 1){
            if(a[i] > 0){
                dp[0][i] = a[i];
                dp[1][i] = 1;
            } else {
                dp[0][i] = dp[1][i] = 0;
            }
        } else {
            if(a[i] + dp[0][i - 2] > dp[0][i - 1]){
                dp[0][i] = a[i] + dp[0][i - 2];
                dp[1][i] = dp[1][i - 2] + 1;
            } else {
                dp[0][i] = dp[0][i - 1];
                dp[1][i] = dp[1][i - 1];
            }
        }
    }
    E = dp[0][n-1];
    T = dp[1][n-1];
    reset(dp);
    up(i, 2, n){
        if(i == 2){
            if(a[i] > 0){
                dp[0][i] = a[i];
                dp[1][i] = 1;
            } else {
                dp[0][i] = dp[1][i] = 0;
            }
        } else {
            if(a[i] + dp[0][i - 2] > dp[0][i - 1]){
                dp[0][i] = a[i] + dp[0][i - 2];
                dp[1][i] = dp[1][i - 2] + 1;
            } else {
                dp[0][i] = dp[0][i - 1];
                dp[1][i] = dp[1][i - 1];
            }
        }
    }
    if(dp[0][n] > E){
        E = dp[0][n];
        T = dp[1][n];
    } else if(dp[0][n] == E){
        T = min(T, dp[1][n]);
    }
    cout << E << ' ' << T << endl;
    return 0;
}
