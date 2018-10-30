#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;
int n,m;
pll H[1005],G[1005];
ll Ti[1005][1005][2]={0};
ll cal(pll a,pll b){
    return (a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S);
}
int main(){
	ios_base::sync_with_stdio(0);
	fr("THAMBO.INP");
	fw("THAMBO.OUT");
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>H[i].F>>H[i].S;
	}
	for(int i=1;i<=m;i++){
        cin>>G[i].F>>G[i].S;
	}
	for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<2;k++) Ti[i][j][k]=1e18;
        }
	}
	Ti[1][0][0]=0;
	for(int i=2;i<=n;i++) Ti[i][0][0]=Ti[i-1][0][0]+cal(H[i-1],H[i]);
	for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            Ti[i][j][0]=min(Ti[i-1][j][0]+cal(H[i-1],H[i]),Ti[i-1][j][1]+cal(G[j],H[i]));
            Ti[i][j][1]=min(Ti[i][j-1][0]+cal(H[i],G[j]),Ti[i][j-1][1]+cal(G[j-1],G[j]));
//            cout<<i<<" "<<j<<" "<<0<<" "<<Ti[i][j][0]<<endl;
//            cout<<i<<" "<<j<<" "<<1<<" "<<Ti[i][j][1]<<endl;
        }
	}
	cout<<Ti[n][m][0]<<endl;
	return 0;
}
