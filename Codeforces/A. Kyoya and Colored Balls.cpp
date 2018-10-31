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
ll a[1005][1005],Ti=1,mod=1e9+7,k,t,sum=0;
int main(){
    ios_base::sync_with_stdio(false);
    for(int i=1;i<=1000;i++) a[0][i]=1,a[1][i]=i;
    for(int i=2;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            a[i][j]=(a[i][j-1]%mod+a[i-1][j-1]%mod)%mod;
        }
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>t;
        if(i!=1) Ti*=(a[t-1][sum+t-1]%mod),Ti%=mod;
        sum+=t;
    }
    cout<<Ti<<endl;
    return 0;
}



