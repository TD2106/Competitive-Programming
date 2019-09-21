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
int keys[] = {0, 1, 2, 3}, freqs[] = {0, 34, 8, 50}, dp[105][105] = {0}, sum[105][105] = {0};
void initSumArray(int n){
    up(i, 1, n){
        up(j, i, n){
            sum[i][j] = sum[i][j - 1] + freqs[j];
        }
    }
}
int optimalSearchTree(int n){
    up(i, 1, n){
        up(j, i, n){
            dp[i][j] = 2e9;
        }
    }
    up(i, 1, n){
        dp[i][i] =freqs[i];
    }
    up(len, 2, n){
        up(i, 1, n - len + 1){
            int j = i + len - 1;
            up(root, i, j){
                dp[i][j] = min(dp[i][j], sum[i][j] + dp[i][root - 1] + dp[root + 1][j]);
            }
        }
    }
    return dp[1][n];
}
int main(){
    ios_base::sync_with_stdio(0);
    initSumArray(3);
    cout << optimalSearchTree(3);
    return 0;
}
