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

int main(){
    ll a,b,c,Ti=1e18,m;
    cin >> a >> b >> c;
    m = min(a,b);
    m = min(m,c);
    a-=m,b-=m,c-=m;
    if(a>=b&&a>=c){
        Ti=max(b,c)-min(b,c);
        Ti+=2*(a-max(b,c))-2;
        cout<<Ti<<endl;
    }
    else if(b>=a&&b>=c){
        if(c>0) c--,b--;
        else Ti=1,b--;
        if(a>=b&&a>=c){
            Ti=max(b,c)-min(b,c);
            Ti+=2*(a-max(b,c))-2;
            cout<<Ti<<endl;
        }
        else{
            Ti=max(b,c)-min(b,c);
            Ti+=2*(a-max(b,c))-2;
            cout<<Ti<<endl;
        }
    }
    return 0;
}



