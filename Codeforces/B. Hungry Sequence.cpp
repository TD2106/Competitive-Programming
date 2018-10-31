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
bitset<1300005> mark;
int main(){
    vll Ti;
    ll n;
    mark[0]=mark[1]=1;
    for(ll i=2;i<=1300000;i++){
        if(!mark[i]){
            Ti.pb(i);
            for(ll j=i*i;j<=1300000;j+=i) mark[j]=1;
        }
        if(Ti.size()==100000) break;
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<Ti[i]<<" ";
    }
    return 0;
}



