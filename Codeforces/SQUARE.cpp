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
#define mod 1000000007
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
map<ll,ll> store;
ll fastpow(int n){
    if(store[n]) return store[n];
    else if(n==1) return 4;
    else if(n==0) return 1;
    else{
        if(n%2) return store[n]=(4*fastpow(n/2)*fastpow(n/2))%mod;
        else return store[n]=(fastpow(n/2)*fastpow(n/2))%mod;
    }
}
int main(){
    fr("SQUARES.INP");
    fw("SQUARES.OUT");
    //ios_base::sync_with_stdio(false);
    ll n,l,Ti=0;
    cin>>n>>l;
    Ti=(fastpow(n+1)-1+mod)%mod;
    Ti=Ti*(333333336%mod)%mod;
    l=l*l;
    l%=mod;
    Ti*=l;
    Ti%=mod;
    cout<<Ti<<endl;
    return 0;
}



