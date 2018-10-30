#include <bits/stdc++.h>
#define bug(x) cout<<#x<<'='<<x<<'\n'
#define tc() int tc;cin>>tc;for(int _tc=0;_tc<tc;++_tc)
#define up(i,l,r) for(int i=l;i<=r;++i)
#define down(i,r,l) for(int i=r;i>=l;--i)
#define fw(file) freopen(file,"w",stdout)
#define fr(file) freopen(file,"r",stdin)
#define reset(x) memset(x,0,sizeof(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mod 1000000007
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
ll fastPow(ll base,ll k){
    ll res=1;
    while(k){
        if(k%2) res*=base;
        base*=base;
        k/=2;
        base%=mod;
        res%=mod;
    }
    return res;
}
ll factorial[100005];
int main()
{
    ios_base::sync_with_stdio(0);
//    fr("in.INP");
//    fw("out.OUT");
    factorial[0]=factorial[1]=1;
    for(ll i=2;i<=100000;i++){
        factorial[i]=(factorial[i-1]*i) % mod;
    }
    tc()
    {
        ll a,b;
        cin>>a>>b;
        cout<<(2*factorial[a-1]*fastPow((factorial[b]*factorial[a-b-1]) % mod,mod-2))%mod<<endl;
    }

}
