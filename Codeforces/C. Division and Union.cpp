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
typedef pair<pii, int> piii;
int tc, n, a, b, two, ans[100005], mx;
vector<piii> segments;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> tc;
    while(tc--){
        segments.clear();
        cin >> n;
        up(i, 1, n){
            cin >> a >> b;
            segments.pb({{a, b}, i});
        }
        sort(all(segments));
        two = - 1;
        mx = segments[0].fi.se;
        up(i, 1, n - 1){
            if(segments[i].fi.fi > mx){
                two = i;
                break;
            } else {
                mx = max(mx, segments[i].fi.se);
            }
        }
        if(two == -1){
            cout << -1;
        } else {
            up(i, 0, n - 1){
                if(i >= two) ans[segments[i].se] = 2;
                else ans[segments[i].se] = 1;
            }
            up(i, 1, n) cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
