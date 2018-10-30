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

int main(){
    ll n,k,t,c=0;
    vll re;
    cin>>n>>k;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            if(++c==k){
                cout<<i<<endl;
                return 0;
            }
            if(i!=(n/i)) re.pb(n/i);
        }
    }

    if(c+re.size()<k){
        cout<<-1<<endl;
        return 0;
    }
    else{
        cout<<re[re.size()-(k-c)];
    }
    return 0;
}



