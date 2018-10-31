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
ll n,p,t;
bool isPrime[1000005]={0};
ll solve(ll x){
    ll l=1,r=1e6,mid,Ti=0;
    while(l<=r){
        ll mid=(l+r)/2;
        if(mid*mid<=x){
            Ti=max(Ti,mid);
            l=mid+1;
        }
        else r=mid-1;
    }
    return Ti;
}
void primeSieve(){
    memset(isPrime,1,sizeof(isPrime));
    for(ll i=2;i*i<=1e6;i++){
        if(isPrime[i]){
            for(ll j=i*i;j<=1e6;j+=i) isPrime[j]=0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    primeSieve();
    cin>>n;
    up(i,1,n){
        cin>>p;
        t=solve(p);
        if(t*t==p&&t!=1&&isPrime[t]) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
