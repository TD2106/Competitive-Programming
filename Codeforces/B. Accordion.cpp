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
string s;
int ans = 0, openIdx = 1e9, closeIdx = -1, n;
bool close = false, open = false;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> s;
    n = s.size();
    up(i, 0, n - 1){
        if(s[i] == '['){
            open = true;
        }
        if(s[i] == ':' && open){
            openIdx = i;
            break;
        }
    }
    down(i, n - 1, 0){
        if(s[i] == ']'){
            close = true;
        }
        if(s[i] == ':' && close){
            closeIdx = i;
            break;
        }
    }
    if(openIdx >= closeIdx){
        cout << -1 << endl;
        return 0;
    }
    up(i, openIdx + 1, closeIdx - 1){
        if(s[i] == '|') ans++;
    }
    ans += 4;
    cout << ans << endl;
    return 0;
}
