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
    ll n,m,k,l,d,t;
    cin>>n>>m>>k;
    t=k;
    l=(ll)ceil(k*1.0/(2*m));
    k-=(l-1)*(2*m);
    d=(ll)ceil(k*1.0/2);
    cout<<l<<" "<<d<<" ";
    if(t%2) cout<<"L"<<endl;
    else cout<<"R"<<endl;
    return 0;
}



