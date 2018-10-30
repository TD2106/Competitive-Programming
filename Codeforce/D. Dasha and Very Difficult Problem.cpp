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
int a[100005]={0},b[100005]={0},n,l,r,mn=2000000000,mx=-2000000000,t;
pii p[100005];
int main(){
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>p[i].fi,p[i].se=i;
    sort(p+1,p+1+n);
    for(int i=1;i<=n;i++){
        b[p[i].se]=a[p[i].se]+(i-1);
        mn=min(b[p[i].se],mn);
        mx=max(b[p[i].se],mx);
    }
    if(mx>r){
        t=mx-r;
        if(mn-t<l){
             cout<<-1<<endl;
             return 0;
        }
        for(int i=1;i<=n;i++){
            cout<<b[i]-t<<" ";
        }
    }
    else{
        for(int i=1;i<=n;i++){
            cout<<b[i]<<" ";
        }
    }
    return 0;
}



