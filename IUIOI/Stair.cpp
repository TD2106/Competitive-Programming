#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll dp[505][505]={0},n,Ti=0;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(i==j) dp[i][j]=1;
            else for(int k=min(i-j,j-1);k>=1;k--) dp[i][j]+=dp[i-j][k];
        }
    }
    for(int i=1;i<n;i++) Ti+=dp[n][i];
    cout<<Ti<<endl;
	return 0;
}
