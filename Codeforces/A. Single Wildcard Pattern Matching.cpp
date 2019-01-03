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
int n, m, asteriskIndex = - 1;
string s, t;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> s >> t;
    up(i, 0, n - 1){
        if(s[i] == '*'){
            asteriskIndex = i;
            break;
        } else if(i >= m || s[i] != t[i]){
            cout << "NO\n";
            return 0;
        }
    }
    if(asteriskIndex == n - 1){
        cout << "YES\n";
        return 0;
    }
    int j = m - 1;
    down(i, n - 1, asteriskIndex + 1){
        if(j < 0 || s[i] != t[j]){
            cout << "NO\n";
            return 0;
        } else {
            j--;
        }
    }
    if(asteriskIndex != -1 && n - 1 > m || asteriskIndex == -1 && n < m) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}
