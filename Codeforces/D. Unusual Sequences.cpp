#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
map<ll,ll> memorize;
ll MOD=1e9+7;
ll fastExpo(ll base,ll k,ll mod){
    base%=mod;
    ll res=1;
    while(k){
        if(k%2) res*=base;
        base*=base;
        k/=2;
        res%=mod;
        base%=mod;
    }
    return res;
}
ll go(ll x){
    if(memorize.count(x)) return memorize[x];
    ll t1=fastExpo(2,x-1,MOD);
    ll t2=0;
    t2+=memorize[1];
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            t2+=go(i);
            t2%=MOD;
            if(i!=x/i){
                t2+=go(x/i);
                t2%=MOD;
            }
        }
    }
    return memorize[x] = (t1 - t2 + MOD)%MOD;
}
int main(){
    ios_base::sync_with_stdio(0);
    ll x,y,Ti=0;
    cin>>x>>y;
    if(y%x){
        cout<<Ti<<endl;
        return 0;
    }
    memorize[1]=1;
    Ti=go(y/x);
    cout<<Ti<<endl;
    return 0;
}
