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
int n, s[100005], q, l, r;
map<pii, pii> dpMap;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    up(i, 1, n) cin >> s[i];
    for(int len = 1; len <= n; len *= 2){
        for(int i = 1; i + len - 1 <= n; i++){
            if(len == 1){
                dpMap[{i, i}] = {s[i], 0};
            } else {
                int sum = (dpMap[{i, i + len / 2 - 1}].fi + dpMap[{i + len / 2, i + len - 1}].fi);
                int f = dpMap[{i, i + len / 2 - 1}].se + dpMap[{i + len / 2, i + len - 1}].se + int(sum >= 10);
                dpMap[{i, i + len - 1}] = { sum % 10, f};
            }
        }
    }
    cin >> q;
    while(q--){
        cin >> l >> r;
        cout << dpMap[{l, r}].se << endl;
    }
    return 0;
}
