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
ll n,k,c[100005],idx[100005],sum=0,Ti=0,m=0;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>c[i],sum+=c[i];
    for(int i=1;i<=k;i++) cin>>idx[i];
    for(int i=1;i<=k;i++){
        m+=c[idx[i]];
        Ti+=c[idx[i]]*(sum-m);
        c[idx[i]]=0;
    }
    for(int i=1;i<n;i++) Ti+=c[i]*c[i+1];
    Ti+=c[1]*c[n];
    cout<<Ti<<endl;
    return 0;
}



