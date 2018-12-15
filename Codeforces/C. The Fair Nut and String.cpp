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
ll MOD = 1e9 + 7, ans = 0, preSum = 0, flag = 0;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> s;
    up(i, 0, s.size() - 1){
        if(s[i] == 'a'){
            ans += (1 + preSum);
            ans %= MOD;
            flag = 1;
        } else if(s[i] == 'b'){
            if(flag){
                preSum = ans * flag;
            }
            preSum %= MOD;
            flag = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
