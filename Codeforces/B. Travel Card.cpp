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
ll n,Ti,temp,idx1,idx2;
vll dp,t;
vll::iterator itr1,itr2;
int main(){
    cin>>n;
    dp.pb(0);
    t.pb(0);
    for(int i=1;i<=n;i++){
        cin>>temp;
        t.pb(temp);
        itr1=lower_bound(all(t),t[i]-89);
        itr2=lower_bound(all(t),t[i]-1439);
        if (*itr1>=t[i]-89) itr1--;
        if(*itr2>=t[i]-1439) itr2--;
        idx1=itr1-t.begin();
        idx2=itr2-t.begin();
        idx1=max(0ll,idx1);
        idx2=max(0ll,idx2);
        Ti=min(20+dp[i-1],min(dp[idx1]+50,dp[idx2]+120));
        dp.pb(Ti);
        /*bug(*itr1);
        bug(*itr2);
        cout<<itr1-dp.begin()<<" "<<itr2-dp.begin()<<endl;*/
        cout<<dp[i]-dp[i-1]<<endl;
    }
    return 0;
}



