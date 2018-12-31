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
int tc, n;
string a, b, aa, bb;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> tc;
    while(tc--){
        cin >> n >> a >> b;
        if(a == b){
            cout << "YES\n";
            continue;
        }
        aa.clear();
        bb.clear();
        up(i, 0, n - 1){
            if(a[i] != b[i]){
                aa += a[i];
                bb += b[i];
            }
        }
        aa += aa[0];
        aa.erase(0, 1);
        if(bb == aa){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
