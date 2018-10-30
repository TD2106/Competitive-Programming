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
#define mod 1000000007
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
ll Ti=0,n,l;
ll fastPow(ll base,ll k){
    ll res=1;
    base%=mod;
    while(k){
        if(k%2) res*=base;
        base*=base;
        res%=mod;
        base%=mod;
        k/=2;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>l;
    l*=l;
    l%=mod;
    n++;
    Ti=((fastPow(4LL,n)-1+mod)%mod)*fastPow(3LL,mod-2);
    Ti%=mod;
    Ti*=l;
    Ti%=mod;
    cout<<Ti<<endl;
    return 0;
}
