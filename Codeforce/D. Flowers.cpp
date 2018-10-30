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
ll n,a,b,sum[100005]={0},dp[100005]={0},k,tc,mod=1e9+7,Ti;
int main(){
    cin>>tc>>k;
    dp[0]=1;
    for(int i=1;i<=100000;i++){
        dp[i]+=dp[i-1]%mod;
        if(i>=k) dp[i]+=dp[i-k]%mod;
        dp[i]%=mod;
    }
    for(int i=1;i<=100000;i++){
        sum[i]+=dp[i]%mod+sum[i-1]%mod;
        sum[i]%=mod;
    }
    while(tc--){
        cin>>a>>b;
        Ti=sum[b]-sum[a-1]+mod;
        Ti%=mod;
        cout<<Ti<<endl;
    }
    return 0;
}



