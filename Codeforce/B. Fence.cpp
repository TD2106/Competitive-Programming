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
ll n,dp[216017]={0},h,Ti,mn=1000000000000,k,t;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>h;
        dp[i]=h+dp[i-1];
    }
    for(int i=1;i<=n-k+1;i++){
        t=dp[i+k-1]-dp[i-1];
        if(t<mn){
            Ti=i;
            mn=t;
        }
    }
    cout<<Ti<<endl;
    return 0;
}



