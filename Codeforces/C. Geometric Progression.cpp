#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll Ti=0,a[200005]={0},n,dp[200005]={0},temp,idx,k;
pll aSort[200005];
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    up(i,1,n){
        cin>>a[i];
        aSort[i].fi=a[i];
        aSort[i].se=i;
    }
    sort(aSort+1,aSort+1+n);
    up(i,2,n){
        if(a[i]%k==0){
            idx = lower_bound(aSort+1,aSort+1+n,mp(a[i],(ll)i)) - aSort;
            temp = upper_bound(aSort+1,aSort+1+n,mp(a[i]/k,(ll)i-1)) - lower_bound(aSort+1,aSort+1+n,mp(a[i]/k,1LL));
            dp[idx]+=temp;
        }
    }
    up(i,1,n) dp[i]+=dp[i-1];
    up(i,2,n){
        if(a[i]%k==0){
            temp = upper_bound(aSort+1,aSort+1+n,mp(a[i]/k,(ll)i-1)) - aSort - 1;
            int temp2 = lower_bound(aSort+1,aSort+1+n,mp(a[i]/k,1LL)) - aSort;
            Ti+=max(0LL,dp[temp]-dp[temp2-1]);
        }
    }
    cout<<Ti<<endl;
    return 0;
}
