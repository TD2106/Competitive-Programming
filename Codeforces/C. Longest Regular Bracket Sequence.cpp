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
typedef pair<char, int> pci;
stack<pci> charIndexStack;
string s;
int matchedIndex[1000005] = {0}, ans = 0, idx = 0, cnt = 1;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> s;
    up(i, 0, s.size() - 1){
        if(charIndexStack.empty() || s[i] == '(' || charIndexStack.top().fi == s[i]){
            charIndexStack.push({s[i], i});
        } else {
            matchedIndex[charIndexStack.top().se] = i;
            charIndexStack.pop();
        }
    }
    while(idx < s.size()){
        if(matchedIndex[idx]){
            int startIdx = idx;
            while(matchedIndex[idx] && idx < s.size()){
                idx = matchedIndex[idx] + 1;
            }
            if(idx - startIdx > ans){
                ans = idx - startIdx;
                cnt = 1;
            } else if(idx - startIdx == ans){
                cnt++;
            }
        } else {
            idx++;
        }
    }
    cout << ans << ' ' << cnt << endl;
    return 0;
}
