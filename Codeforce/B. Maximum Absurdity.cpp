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
ll Ti=0,n,dp[200005]={0},mx[200005]={0},k,idx[200005]={0};
pii ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    up(i,1,n){
        cin>>dp[i];
        dp[i]+=dp[i-1];
    }
    down(i,n-k+1,1){
        if(dp[i+k-1]-dp[i-1]>=mx[i+1]){
            mx[i]=dp[i+k-1]-dp[i-1];
            idx[i]=i;
        }
        else{
            idx[i]=idx[i+1];
            mx[i]=mx[i+1];
        }
    }
    up(i,1,n-2*k+1){
        if(dp[i+k-1]-dp[i-1]+mx[i+k]>Ti){
            ans.fi=i;
            ans.se=idx[i+k];
            Ti=dp[i+k-1]-dp[i-1]+mx[i+k];
        }
        else if(dp[i+k-1]-dp[i-1]+mx[i+k]==Ti){
            ans=min(ans,{i,idx[i+k]});
        }
//        cout<<Ti<<' '<<ans.fi<<' '<<ans.se<<endl;
    }
    cout<<ans.fi<<' '<<ans.se<<endl;
    return 0;
}
