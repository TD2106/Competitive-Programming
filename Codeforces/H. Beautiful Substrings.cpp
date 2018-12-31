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
typedef pair<char, char> pcc;
int tc, n, m, k, cnt[26];
string a, b;
vector< set<char> > possiblePairs;
ll ans = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    possiblePairs.resize(26);
    while(tc--){
        ans = 0;
        up(i, 0, 25){
            cnt[i] = 0;
            possiblePairs[i].clear();;
        }
        cin >> n >> m >> k >> a >> b;
        up(i, 0, n - k){
            possiblePairs[a[i + k - 1] - 'a'].insert(a[i]);
        }
        up(i, 0, m - 1){
            cnt[b[i] - 'a']++;
            for(char c : possiblePairs[b[i] - 'a']){
                ans += cnt[c - 'a'];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
