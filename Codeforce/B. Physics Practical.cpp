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
int n,cnt[5005]={0},t,dp[5001]={0},Ti=1e9,st=1e9,en=0;
int main(){
    /*fr("input.txt");
    fw("output.txt");*/
    cin>>n;
    for(int i=0;i<n;i++) cin>>t,cnt[t]++,st=min(st,t),en=max(en,t);
    for(int i=1;i<=en;i++) dp[i]=dp[i-1]+cnt[i];
    for(int i=0;i<=en;i++) cout<<dp[i]<<endl;
    for(int i=st;i<=en;i++){
         //cout<<i<<" "<<n-(dp[min(en,2*i)]-dp[i-1])<<endl;
         Ti=min(Ti,n-(dp[min(en,2*i)]-dp[i-1]));
    }
    cout<<Ti<<endl;
    return 0;
}



