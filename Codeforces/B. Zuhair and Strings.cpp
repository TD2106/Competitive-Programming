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
int n, k, ans = 0, temp;
string s, pattern;
string constructPatternForSearch(char c, int len){
    string pattern = "";
    while(len--){
        pattern += c;
    }
    return pattern;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> k >> s;
    up(i, 0, 25){
        temp = 0;
        string pattern = constructPatternForSearch('a' + i, k);
        size_t foundIndex = s.find(pattern);
        while(foundIndex != string::npos){
            temp++;
            foundIndex = s.find(pattern, foundIndex + (size_t)k);
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
    return 0;
}
