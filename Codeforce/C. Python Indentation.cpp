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
ll mod=1e9+7,n,dp[5005][5005]={0},Ti;
char ch[5005];
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n) cin>>ch[i];
    dp[1][1]=1;
    up(i,1,n){
        if(ch[i]=='f'){
            up(j,1,n) dp[i+1][j+1]+=dp[i][j],dp[i+1][j]%=mod;
        }
        else{
            up(j,1,n){
                 dp[i+1][1]+=dp[i][j];
                 dp[i+1][j+1]-=dp[i][j];
                 dp[i+1][1]%=mod;
                 dp[i+1][j+1]%=mod;
            }
            up(j,1,n){
                dp[i+1][j]+=dp[i+1][j-1];
                dp[i+1][j]+=mod;
                dp[i+1][j]%=mod;
            }
        }
    }
//    up(i,1,n){
//        up(j,1,n) cout<<dp[i][j]<<' ';
//        cout<<endl;
//    }
    up(i,1,n) Ti+=dp[n][i],Ti%=mod;
    cout<<Ti<<endl;
    return 0;
}
