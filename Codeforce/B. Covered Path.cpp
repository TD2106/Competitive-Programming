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

int main(){
    int v1,v2,t,d,dp[101]={0},Ti=0;
    cin>>v1>>v2>>t>>d;
    dp[1]=v1,dp[t]=v2;
    for(int i=2;i<=t-1;i++){
        dp[i]=min(dp[i-1]+d,dp[t]+(t-i)*d);
    }
    for(int i=1;i<=t;i++) Ti+=dp[i];
    cout<<Ti<<endl;
    return 0;
}


