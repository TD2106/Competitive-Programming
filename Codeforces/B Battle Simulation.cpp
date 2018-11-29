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
string s, Ti;
map<char,int> cnt;
void check2Chars(int start){
    cnt['R'] = cnt['B'] = cnt['L'] = 0;
    up(i, start, min(start + 1, int(s.size()) - 1)){
        cnt[s[i]]++;
    }
}
bool isComboBreaker(){
    return (cnt['R'] == 1 && cnt['B'] == 1 && cnt['L'] == 1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> s;
    check2Chars(0);
    up(i, 0, s.size() - 1){
        if(i + 2 <= s.size() - 1){
            cnt[s[i + 2]]++;
        }
        if(isComboBreaker()){
            Ti += 'C';
            i += 2;
            check2Chars(i + 1);
        } else {
            if(s[i] == 'R'){
                Ti += 'S';
            } else if (s[i] == 'B'){
                Ti += 'K';
            } else {
                Ti += 'H';
            }
            cnt[s[i]]--;
        }
    }
    cout << Ti << endl;
    return 0;
}
