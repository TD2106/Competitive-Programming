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
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
vector< pair<int,pii> > coupon(600005);
int n,k,Ti=0,st,en;
set<int> p;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>coupon[i].fi>>coupon[n+i].fi;
        coupon[i].se.fi=1;
        coupon[n+i].se.fi=2;
        coupon[i].se.se=coupon[n+i].se.se=i;
    }
    sort(coupon+1,coupon+1+2*n);
    for(int i=1;i<=2*n;i++){
        if(coupon[i].se.fi==1){

        }
        else p.erase(coupon)
    }
    return 0;
}



