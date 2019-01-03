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
typedef pair<char,int> pci;
stack<char> charStack;
string s, ans;
int n, k, cntOpen = 0, cntClose = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> k >> s;
    up(i, 0, n - 1){
        if(charStack.empty() || s[i] == '(' || charStack.top() == s[i]){
            charStack.push(s[i]);
            if(cntOpen < k / 2){
                ans += '(';
                cntOpen++;
            }
        } else {
            charStack.pop();
            if(cntClose < k / 2){
                ans += ')';
                cntClose++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
