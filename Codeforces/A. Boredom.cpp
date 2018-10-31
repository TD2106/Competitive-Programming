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
ll cnt[100005]={0},n,dp[100005]={0},Ti=0,t;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        cnt[t]++;
        Ti=max(t,Ti);
    }
    dp[1]=cnt[1];
    for(int i=2;i<=Ti;i++){
        dp[i]=max(dp[i-1],dp[i-2]+cnt[i]*i);
    }
    cout<<dp[Ti]<<endl;
    return 0;
}



