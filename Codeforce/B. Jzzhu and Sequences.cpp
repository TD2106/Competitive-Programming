#include <bits/stdc++.h>
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
    ll x,y,n,Ti[6],mod=1e9+7;
    cin>>x>>y>>n;
    Ti[1]=x;
    Ti[2]=y;
    Ti[3]=y-x;
    Ti[4]=-x;
    Ti[5]=-y;
    Ti[0]=x-y;
    n=n%6;
    while(Ti[n]<0) Ti[n]+=mod;
    cout<<Ti[n]%mod<<endl;
    return 0;
}



