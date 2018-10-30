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
string s,s1="abcdefghijklmnopqrstuvwxyz";
int Ti,dp[55][55]={0};
int main(){
	ios_base::sync_with_stdio(0);
	cin>>s;
	up(i,0,s.size()){
        up(j,0,s1.size()){
            if(i==0||j==0) dp[i][j]=0;
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                if(s[i-1]==s1[j-1]){
                    dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
                }
            }
        }
	}
	Ti=s1.size()-dp[s.size()][s1.size()];
	cout<<Ti<<endl;
	return 0;
}
