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
ll Ti=0,n,k,sum[100005]={0},t;
map<ll,ll> cnt;
vll powk;
int main(){
    cin>>n>>k;
    if(k==1) powk.pb(1);
    else if(k==-1) powk.pb(1),powk.pb(-1);
    else{
        t=1;
        while(abs(t)<=(ll)1e15){
            powk.pb(t);
            t*=k;
        }
    }
    for(int i=1;i<=n;i++) cin>>t,sum[i]=sum[i-1]+t;
    for(int i=0;i<=n;i++){
        for(int j=0;j<powk.size();j++){
            if(cnt.count(sum[i]-powk[j])!=0){
                Ti+=cnt[sum[i]-powk[j]];
            }
        }
        cnt[sum[i]]++;
    }
    cout<<Ti<<endl;
    return 0;
}



