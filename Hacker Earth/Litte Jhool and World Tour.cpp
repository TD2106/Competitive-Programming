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
vector<pii> range;
int tc,n,m,x,y,cur,check;
int main(){
    cin>>tc;
    while(tc--){
        cur=0;
        check=0;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            cin>>x>>y;
            if(x<=y) range.pb(mp(x,y));
            else{
                range.pb(mp(x,n-1));
                range.pb(mp(0,y));
            }
        }
        range.pb(-1,-1);
        range.pb(n,n);
        sort(all(range));
        for(int i=1;i<=m;i++){
            if(range[i].fi==range[i].se&&range[i-1].se<range[i].fi&&range[i+1].fi>range[i].se){
                check=1;
                break;
            }

        }
        if(check) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}



