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
int n, a[105] = {0}, temp = 0, ans = 1e9;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    up(i, 1, n) cin >> a[i];
    up(i, 1, n){
        temp = 0;
        up(j, 1, n){
            temp += a[j] * (abs(j - i) + (j - 1) + (i - 1)) * 2;
        }
        ans = min(ans, temp);
    }
    cout << ans << endl;
    return 0;
}
