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
ll n, s, v[1005] = {0}, sum = 0, ans = 2e9;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    up(i, 1, n){
        cin >> v[i];
        sum += v[i];
        ans = min(ans, v[i]);
    }
    if(sum < s){
        cout << -1 << endl;
        return 0;
    }
    sum = 0;
    up(i, 1, n){
        sum += (v[i] - ans);
    }
    if(sum < s){
        ans -= ((s - sum) + n - 1) / n;
    }
    cout << ans << endl;
    return 0;
}
