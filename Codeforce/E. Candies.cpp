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
int tc,n,v[55],dp[55][55];
bool vis[55][55];
int go(int l,int r){
    if(vis[l][r]) return dp[l][r];
    vis[l][r]=1;
    up(i,l+1,r-1){
        dp[l][r]=max(dp[l][r],go(l,i)+go(i,r)+v[i]*min(v[l],v[r]));
    }
    return dp[l][r];
}
void doDp(){
    up(i,1,n) dp[i-1][i+1]=v[i]*min(v[i-1],v[i+1]);
    up(length,2,n){
        up(i,1,n-length+1){
            int j=i+length-1;
            up(k,i,j){
                dp[i-1][j+1]=max(dp[i-1][j+1],dp[i-1][k]+dp[k][j+1]+v[k]*min(v[i-1],v[j+1]));
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>tc;
    while(tc--){
        cin>>n;
        up(i,1,n) cin>>v[i];
        v[0]=1,v[n+1]=1;
        reset(dp);
        reset(vis);
        //cout<<go(0,n+1)<<endl;
        doDp();
        cout<<dp[0][n+1]<<endl;
    }
    return 0;
}
