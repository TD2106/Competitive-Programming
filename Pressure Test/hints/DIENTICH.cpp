#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
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
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define rep(i,a,b,c) for(int i=a;i<b;i+=c)
#define repe(i,a,b,c) for(int i=a;i<=b;i+=c)
#define reset(a) memset(a,0,sizeof(a))
#define nl printf("\n")
#define ri(a) scanf("%d",&a)
#define rll(a) scanf("%lld",&a)
#define rllu(a) scanf("%llu",&a)
#define wi(a) printf("%d",a)
#define wll(a) printf("%lld",a)
#define wllu(a) printf("%llu",a)
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef long double lf;
typedef pair<ll,ll>pii;
typedef vector<int> vi;
typedef vector<ll> vii;

const double pi = 2.0*acos(0.0);
int tc;
double r;

int main(){
    //fr("b.txt");
    //fw("out.txt");

    cin >> tc;
    for(int t=1;t<=tc;t++){
        cin >> r;
        double s1 = (2.0*r)*(2.0*r);
        double s2 = pi*r*r;

        printf("Case %d: %.2f\n",t,(s1-s2));
    }

    return 0;
}




