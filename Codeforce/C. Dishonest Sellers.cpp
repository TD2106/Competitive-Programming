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
#define M 200005
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
ll n,k,a[M],b[M],Ti=0,idx[M],cnt=0;
bool cmp(ll c,ll d){
    return (a[c]-b[c])<(a[d]-b[d]);
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        idx[i]=i;
    }
    for(int i=0;i<n;i++) cin>>b[i];
    sort(idx,idx+n,cmp);
    //for(int i=0;i<n;i++) cout<<idx[i]<<endl;
    while((cnt<k||(a[idx[cnt]]-b[idx[cnt]])<=0)&&cnt<n){
        Ti+=a[idx[cnt]];
        cnt++;
    }
    for(int i=cnt;i<n;i++) Ti+=b[idx[i]];
    cout<<Ti<<endl;
    return 0;
}



