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
vi a;
vector<pii> b;
bool cmp(pii c,pii d){
    return (a[c.se]<a[d.se]);
}
int main(){
    vi::iterator itr;
    int dp[100005]={0},n,t1,t2,Ti=0;
    a.pb(0),b.pb(mp(0,0));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t1>>t2;
        a.pb(t1);
        b.pb(mp(t2,i));
    }
    sort(all(b),cmp);
    sort(all(a));
    for(int i=1;i<=n;i++){
        itr=lower_bound(all(a),a[i]-b[i].fi);
        if(itr!=a.begin()) itr--;
        dp[i]=1+dp[itr-a.begin()];
        Ti=max(Ti,dp[i]);
    }
    //for(int i=0;i<=n;i++){
    //   bug(dp[i]);
    //}
    cout<<n-Ti<<endl;
    return 0;
}



