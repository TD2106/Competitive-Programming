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

/*
 * Code begins here
 */

#define N 1000000
unsigned int mark[N / 64];
#define gP(n) (mark[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (mark[n>>6]&=~(1<<((n>>1)&31)))

int cnt[N + 1];

void sieve() {
    memset( mark, -1, sizeof( mark ) );
    unsigned int i;
    unsigned int sqrtN = ( unsigned int )sqrt( ( double )N ) + 1;

    for( i = 3; i < sqrtN; i += 2 ) if( gP( i ) ) {
        unsigned int i2 = i + i;
        for( unsigned int j = i * i; j < N; j += i2 ) rP( j );
    }
    cnt[1] = 1;
    cnt[2] = 1;
    for( i = 3; i < N; i += 2)
        if (gP(i)) cnt[i] = 1;

    for(int i=1; i <= N; ++i) cnt[i] += cnt[i-1];
}

int main() {
    /*string _test = "9";
    string in = _test + ".in";
    string out = _test + ".ans";

    freopen(in.c_str(),"r",stdin);
    freopen(out.c_str(),"w",stdout);*/

    /*
     * Main program starts from here
     */

    sieve();
    int ntest; cin >> ntest;
    for(int test = 1; test <= ntest; ++test) {
        int n; cin >> n;
        cout << "Case #" << test << ": " << cnt[n] << endl;
    }

    /*
     * Main program ends from here
     */

    return 0;
}

/*
 * Code ends here
 */


