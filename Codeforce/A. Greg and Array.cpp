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
typedef pair<pii,int> piii;
ll n,m,k,a[100005]={0},Ti[100005]={0},dp[100005]={0},x,y;
piii query[100005];
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    up(i,1,n) cin>>a[i];
    up(i,1,m){
        cin>>query[i].fi.fi>>query[i].fi.se>>query[i].se;
    }
    up(i,1,k){
        cin>>x>>y;
        dp[x]++;
        dp[y+1]--;
    }
    up(i,1,m) dp[i]+=dp[i-1];
    up(i,1,m){
        Ti[query[i].fi.fi]+=dp[i]*((ll)query[i].se);
        Ti[query[i].fi.se+1]-=dp[i]*((ll)query[i].se);
    }
    up(i,1,n) Ti[i]+=Ti[i-1];
    up(i,1,n) Ti[i]+=a[i];
    up(i,1,n) cout<<Ti[i]<<' ';
    return 0;
}
