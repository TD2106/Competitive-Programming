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
typedef vector<ll> vll;
int ul[505][505], ur[505][505], dl[505][505], dr[505][505], n , m, tc, ans;
void resetArray(){
    up(i, 0, m + 1){
        ul[0][i] = ur[0][i] = dl[0][i] = dr[0][i] = 0;
        ul[n + 1][i] = ur[n + 1][i] = dl[n + 1][i] = dr[n + 1][i] = 0;
    }

    up(i, 0, n + 1){
        ul[i][0] = ur[i][0] = dl[i][0] = dr[i][0] = 0;
        ul[i][m + 1] = ur[i][m + 1] = dl[i][m + 1] = dr[i][m + 1] = 0;
    }
}
int main(){
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &n, &m);
        resetArray();
        up(i, 1, n){
            up(j, 1, m){
                scanf("%d", &ul[i][j]);
                ur[i][j] = dl[i][j] = dr[i][j] = ul[i][j];
            }
        }
        up(i, 1, n){
            up(j, 1, m){
                ul[i][j] = max(ul[i][j], max(ul[i - 1][j], max(ul[i][j - 1], ul[i - 1][j - 1])));
            }
        }
        up(i, 1, n){
            down(j, m, 1){
                ur[i][j] = max(ur[i][j], max(ur[i - 1][j], max(ur[i][j + 1], ur[i - 1][j + 1])));
            }
        }
        down(i, n, 1){
            up(j, 1, m){
                dl[i][j] = max(dl[i][j], max(dl[i + 1][j], max(dl[i][j - 1], dl[i + 1][j - 1])));
            }
        }
        down(i, n, 1){
            down(j, m, 1){
                dr[i][j] = max(dr[i][j], max(dr[i + 1][j], max(dr[i][j + 1], dr[i + 1][j + 1])));
            }
        }
        ans = 1e9;
        up(i, 2, n - 1){
            up(j, 2, m - 1){
                vi temp;
                temp.pb(ul[i - 1][j - 1]);
                temp.pb(ur[i - 1][j + 1]);
                temp.pb(dl[i + 1][j - 1]);
                temp.pb(dr[i + 1][j + 1]);
                sort(all(temp));
                ans = min(ans, temp[3] - temp[0]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
