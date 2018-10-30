#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <ctime>

#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define reset(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define pb push_back
#define ins insert
#define mp make_pair
#define fi first
#define se second
#define bug(x) cout << #x << " = " << x << endl;
#define tc() int tc; cin >> tc; for(int _tc=0;_tc<tc;_tc++)
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;

long long pow10(int e){
    if(e==0) return 1ll;
    if(e==1) return 1ll*10;
    return 10*pow10(e-1);
}

int cnt[111];
bool check(long long n, int k) {
    for(int i = 0; i < k; ++i)
        cnt[i] = 0;

    long long u = n;
    while (u) {
        cnt[u % 10]++;
        u /= 10;
    }

    for(int pos = k-1; pos >= 0; --pos)
        if (cnt[pos] != n % 10) return false;
        else n /= 10;
    return true;
}

int main() {
    /*string test = "";
    string in = test + ".in";
    string out = test + ".ans";

    freopen(in.c_str(),"r",stdin);
    freopen(out.c_str(),"w",stdout);*/

    int ntest; cin >> ntest;
    while (ntest--) {
        int k; cin >> k;

        if(k>6){
            if(k==7) cout << 3211000 << endl;
            if(k==8) cout << 42101000 << endl;
            if(k==9) cout << 521001000 << endl;
            if(k==10) cout << 6210001000 << endl;
        }else{
            long long lb = 1; for(int turn = 0; turn < k-1; ++turn) lb *= 10;
            long long ub = 1; for(int turn = 0; turn < k; ++turn) ub *= 10; --ub;

            bool ok = false;
            for(long long x = lb; x <= ub; ++x) {
                if (check(x, k)) {
                    ok = true;
                    cout << x << ' ';
                }
            }
            if (!ok) cout << -1 << endl;
            else cout << endl;
        }
    }

}
