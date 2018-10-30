#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,k,dp[3][21][100005]={0},a[100005],Ti=0;
int convert(char c){
    if(c=='P') return 0;
    else if(c=='H') return 1;
    else return 2;
}
int isWin(int f,int s){
    if(f==2&&s==0||f==0&&s==1||f==1&&s==2) return 1;
    else return 0;
}
int main(){
	ios_base::sync_with_stdio(0);
	fr("OANTUTI.INP");
	fw("OANTUTI.OUT");
	cin>>n>>k;
	for(int i=1;i<=n;i++){
        char temp;
        cin>>temp;
        a[i]=convert(temp);
	}
	for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            for(int l=0;l<=k;l++){
                if(l==0){
                    dp[j][l][i]=dp[j][l][i-1]+isWin(j,a[i]);
                }
                else{
                    dp[j][l][i]=dp[j][l][i-1]+isWin(j,a[i]);
                    dp[j][l][i]=max(dp[j][l][i],dp[(j+1)%3][l-1][i-1]+isWin(j,a[i]));
                    dp[j][l][i]=max(dp[j][l][i],dp[(j+2)%3][l-1][i-1]+isWin(j,a[i]));
                }
            }
        }
	}
	for(int i=0;i<3;i++){
        for(int j=0;j<=k;j++) Ti=max(Ti,dp[i][j][n]);
	}
	cout<<Ti<<endl;
	return 0;
}
