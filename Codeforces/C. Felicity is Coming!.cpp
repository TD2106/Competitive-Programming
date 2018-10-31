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
ll n,m,Ti=1,t=1,g,mod=1000000007;
vector< vector<int> > pkm;
int main(){
    cin>>n>>m;
    pkm.resize(m);
    for(int i=0;i<n;++i){
        cin>>g;
        while(g--){
            cin>>t;
            pkm[--t].pb(i);
        }
    }
    sort(all(pkm));
    t=1;
    for(int i=1;i<m;i++){
        if(pkm[i]==pkm[i-1]) t++;
        else t=1;
        t%=mod;
        Ti=(Ti*t)%mod;
    }
    cout<<Ti<<endl;
    return 0;
}
