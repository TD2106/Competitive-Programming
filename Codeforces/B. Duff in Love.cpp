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
bool marking[1000000+1]={0};
set<ll> primefac;
vll prime;
int main(){
    for(ll i=2;i<=1000000;i++){
        if(!marking[i]){
            prime.pb(i);
            for(ll j=i*i;j<=1000000;j+=i) marking[j]=1;
        }
    }
    ll n,Ti=1;
    cin>>n;
    for(int i=0;i<prime.size()&&n>=prime[i];i++){
        if(n%prime[i]==0) primefac.insert(prime[i]);
        while(n%prime[i]==0) n/=prime[i];
    }
    if(n!=1) primefac.insert(n);
    for(set<ll>::iterator itr=primefac.begin();itr!=primefac.end();itr++){
        Ti*=(*itr);
    }
    cout<<Ti<<endl;
    return 0;
}



