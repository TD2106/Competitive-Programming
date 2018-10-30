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
string s;
int dp[5005][5]={0},Ti=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>s;
    up(i,1,s.size()) dp[i][1]=dp[i][2]=dp[i][3]=2e9;
    up(i,1,s.size()){
        if(s[i-1]=='a'){
            dp[i][1]=dp[i-1][1];
            dp[i][2]=1+min(dp[i-1][1],dp[i-1][2]);
            dp[i][3]=min(min(dp[i-1][3],dp[i-1][1]),dp[i-1][2]);
        }
        else{
            dp[i][1]=1+dp[i-1][1];
            dp[i][2]=min(dp[i-1][1],dp[i-1][2]);
            dp[i][3]=1+min(min(dp[i-1][3],dp[i-1][1]),dp[i-1][2]);
        }
    }
    Ti=max(s.size()-dp[s.size()][1],max(s.size()-dp[s.size()][2],s.size()-dp[s.size()][3]));
    cout<<Ti<<endl;
    return 0;
}
