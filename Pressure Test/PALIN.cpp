#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
string s,rev;
int Ti=0,dp[5005][5005]={0},n;
int main(){
	ios_base::sync_with_stdio(0);
    fr("PALIN.INP");
    fw("PALIN.OUT");
	cin>>n>>s;
	for(int i=s.size()-1;i>=0;i--) rev+=s[i];
	for(int i=0;i<=s.size();i++){
        for(int j=0;j<=s.size();j++){
            if(i==0||j==0) dp[i][j]=0;
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                if(s[i-1]==rev[j-1]) dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j]);
            }
        }
	}
	Ti=s.size()-dp[s.size()][s.size()];
	cout<<Ti<<endl;
	return 0;
}
