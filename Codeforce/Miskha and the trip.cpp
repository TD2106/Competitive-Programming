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

ll n,k,sum,ans,tmp,sumCap;
ll c[100007];
bool cap[100007];

ll pre(ll x){
    if(x==1) return n;
    return x-1;
}

ll next(ll x){
    if(x==n) return 1;
    return x+1;
}

int main(){
    //fr("b.txt");
    //fw("out.txt");

    cin >> n >> k;
    ans = sum = sumCap = 0;
    reset(cap);

    for(ll i=1;i<=n;i++){
        cin >> c[i];
        sum += c[i];
        if(i>=2) ans+=(c[i]*c[i-1]);
    }
    ans+=(c[n]*c[1]);

    for(ll i=1;i<=k;i++){
        cin >> tmp;
        cap[tmp] = 1;
        ll l = pre(tmp);
        ll r = next(tmp);

        ll k = (sum-c[l]-c[r]-c[tmp]-sumCap);
        if(cap[l]) k = k+c[l];
        if(cap[r]) k = k+c[r];
        k*=c[tmp];
        ans+=k;

        sumCap+=c[tmp];
    }
    cout << ans << endl;

    return 0;
}




