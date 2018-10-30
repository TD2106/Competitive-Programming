#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
int tc,dp[10005][7]={0},Ti,n;
vector<int> side[7];
int main(){
	ios_base::sync_with_stdio(0);
	side[1]={2,3,4,5};
	side[2]={1,3,4,6};
	side[3]={1,2,5,6};
	side[4]={1,2,5,6};
	side[5]={1,3,4,6};
	side[6]={2,3,4,5};
	for(int i=1;i<=10000;i++){
        for(int j=1;j<=6;j++){
            dp[i][j]=1e9;
        }
	}
	dp[2][2]=1;
	dp[3][3]=1;
	dp[4][4]=1;
	dp[5][5]=1;
	for(int i=2;i<=10000;i++){
        for(int j=1;j<=6;j++){
            for(int k:side[j]){
                dp[i+k][k]=min(dp[i+k][k],dp[i][j]+1);
            }
        }
	}
	cin>>tc;
	while(tc--){
        cin>>n;
        Ti=1e9;
        for(int j=1;j<=6;j++) Ti=min(Ti,dp[n][j]);
        if(Ti==1e9) Ti=-1;
        cout<<Ti<<endl;
	}
	return 0;
}
