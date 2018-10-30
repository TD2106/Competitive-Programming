#include <cstdio>
#include <cstring>
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

ll d,k,a,b,t,rs;

int main(){
    //fr("d.txt");
    //fw("out.txt");

    cin >> d >> k >> a >> b >> t;

    rs = 0;
    if(d>=k){
        rs+=(min(a,b)*k);
        d-=k;
    }
    ll nK = d/k;
    rs+=(nK*min(k*b,t+k*a));
    d-=(nK*k);

    if(d!=0){
        rs+=min(d*b,t+d*a);
    }
    cout << rs << endl;

    return 0;
}




