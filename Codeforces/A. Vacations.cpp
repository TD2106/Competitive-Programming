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

int main(){
    int n,a[105]={0},dp[105]={0},Ti=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]==0) dp[i]==0;
        else{
            if(a[i]==1&&dp[i-1]!=1) dp[i]=1;
            else if(a[i]==2&&dp[i-1]!=2) dp[i]=2;
            else if(a[i]==3){
                if(dp[i-1]==0||dp[i-1]==3) dp[i]=3;
                else if(dp[i-1]==1) dp[i]=2;
                else dp[i]=1;
            }
        }
    }
    for(int i=1;i<=n;i++) Ti+=(dp[i]==0);
    cout<<Ti<<endl;
    return 0;
}



