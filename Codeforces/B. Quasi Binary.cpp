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
int quasib[]={1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111,10000,10001,10010,10011,10100,10101,10110,10111,11000,11001,11010,11011,11100,11101,11110,11111,
100000,100001,100010,100011,100100,100101,100110,100111,101000,101001,101010,101011,101100,101101,101110,101111,110000,110001,110010,110011,110100,110101,110110,110111,111000,111001,111010,111011,111100,111101,111110,111111,1000000};
vector<int> quasi(quasib,quasib+sizeof(quasib)/sizeof(int));
int n,dp[1000001]={0},t;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) dp[i]=2000000000;
    for(int i=1;i<=n;i++){
        for(int j=0;j<quasi.size()&&quasi[j]<=i;j++){
            if((i-quasi[j])!=0&&dp[i-quasi[j]]==0) continue;
            dp[i]=min(dp[i],1+dp[i-quasi[j]]);
        }
    }
    cout<<dp[n]<<endl;
    t=n;
    for(int i=0;i<dp[n];i++){
        for(int j=0;j<quasi.size()&&quasi[j]<=t;j++){
            if(dp[t-quasi[j]]==dp[t]-1){
                cout<<quasi[j]<<" ";
                t-=quasi[j];
                break;
            }
        }
    }
    return 0;
}



