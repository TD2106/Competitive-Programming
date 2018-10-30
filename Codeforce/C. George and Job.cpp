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
ll Ti=0,n,m,k,dp[5005][5005]={0},a[5005],sum[5005]={0};
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(j-m>=0) dp[i][j]=max(dp[i-1][j-m]+(sum[j]-sum[j-m]),dp[i][j-1]);
        }
    }
    /*for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++) cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    for(int i=1;i<=n;i++) Ti=max(Ti,dp[k][i]);
    cout<<Ti<<endl;
    return 0;
}



