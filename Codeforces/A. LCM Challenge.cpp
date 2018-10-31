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
ll gcd(ll a,ll b){
    if(a*b==0) return a+b;
    else return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
int main(){
    ll n,mn,Ti=0,t;
    cin>>n;
    if(1>=n-30) mn=1;
    else mn=n-30;
    for(ll i=n;i>=mn;i--){
        for(ll j=n;j>=mn;j--){
            for(ll k=n;k>=mn;k--){
                t=lcm(i,j);
                t=lcm(t,k);
                Ti=max(Ti,t);
            }
        }
    }
    cout<<Ti<<endl;
    return 0;
}



