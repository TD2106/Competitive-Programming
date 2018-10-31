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
int l,r,n,v[300005]={0},k,Ti=1e9,mid;
int dp[300005];
bool check(int x){
    reset(dp);
    dp[0]=1;
    if(v[k]-v[1]<=x) dp[k]=1;
    else return 0;
    up(i,1,k) dp[i]+=dp[i-1];
    up(i,k+1,n){
        int idx=lower_bound(v+1,v+1+n,v[i]-x) - v;
        if(idx-2>=0) {if(dp[i-k]-dp[idx-2]>=1) dp[i]=1;}
        else dp[i]=1;
        dp[i]+=dp[i-1];
//        if(x==58){
//            bug(idx);
//            bug(i-k);
//            bug(i);
//            bug(dp[i]);
//            bug(v[i]);
//        }
    }
    return dp[n]-dp[n-1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    up(i,1,n) cin>>v[i];
    sort(v+1,v+1+n);
    l=0,r=1e9;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            r=mid-1;
            Ti=min(Ti,mid);
        }
        else l=mid+1;
    }
    cout<<Ti<<endl;
    return 0;
}
