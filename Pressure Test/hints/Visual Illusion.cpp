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

int t;
int n;
int i,j;

int main() {
    /*string _test = "9";
    string in = _test + ".in";
    string out = _test + ".ans";

    freopen(in.c_str(),"r",stdin);
    freopen(out.c_str(),"w",stdout);*/

    /*
     * Main program starts from here
     */
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        for (i = -n; i<=n; i++)
        {
            for (j = -n; j <= n; j++)
            {
                if ((abs(i) + abs(j)) % 3 == 0)
                    printf("b");
                else
                    printf("w");
            }
            printf("\n");
        }
    }

    /*
     * Main program ends from here
     */

    return 0;
}

/*
 * Code ends here
 */


