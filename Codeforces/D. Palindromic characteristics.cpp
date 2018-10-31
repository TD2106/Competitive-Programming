#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int Ti[5005]={0},n,dp[5005][5005]={0};
string s;
bool isPalin[5005][5005]={0};
int main(){
	ios_base::sync_with_stdio(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++) isPalin[i][i]=1;
	for(int l=2;l<=n;l++){
        for(int i=0;i<n-l+1;i++){
            int j=i+l-1;
            if(l==2&&s[i]==s[j]) isPalin[i][j]=1;
            if(l!=2){
                if(s[i]==s[j]&&isPalin[i+1][j-1]) isPalin[i][j]=1;
            }
        }
	}
    for(int i=0;i<n;i++) dp[i][i]=1,Ti[1]++;
   // cout<<Ti[1]<<endl;
	for(int l=2;l<=n;l++){
        for(int i=0;i<n-l+1;i++){
            int j=i+l-1;
            if(isPalin[i][j]){
                if(dp[i][i+l/2-1]==dp[i+(l+1)/2][j]) dp[i][j]=dp[i][i+l/2-1]+1;
                else dp[i][j]=1;
                Ti[dp[i][j]]++;
            }
        }
	}
	for(int i=n;i>=1;i--) Ti[i]+=Ti[i+1];
	for(int i=1;i<=n;i++) cout<<Ti[i]<<" ";
	return 0;
}
