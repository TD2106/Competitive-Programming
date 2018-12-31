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
int pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000}, tc;
string a, b;
vi special(string x){
    vi result;
    int isNegative = 1;
    if(x[0] == '-'){
        isNegative = -1;
    }
    reverse(all(x));
    if(isNegative == -1){
        x.pop_back();
    }
    up(i, 0, x.size() - 1){
        if(x[i] != '0'){
            result.pb((x[i] - '0') * pow10[i] * isNegative);
        }
    }
    return result;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> tc;
    while(tc--){
        cin >> a >> b;
        vi specialA = special(a);
        vi specialB = special(b);
        for(int i : specialA){
            for(int j : specialB){
                cout << i << " x " << j;
                if(i != specialA.back() || j != specialB.back()){
                    cout << " + ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}
