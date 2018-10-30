#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define F first
#define S second
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<pii,ll> piil;
ll dp[15][105][105]={0},Ti,temp[105][105];
piil star[100005];
int n,x,y,s,c,q,u,v,t;
int main(){
	ios_base::sync_with_stdio(0);
    cin>>n>>q>>c;
    for(int i=1;i<=n;i++) cin>>star[i].F.F>>star[i].F.S>>star[i].S;
    for(int i=0;i<=c;i++){
        reset(temp);
        for(int j=1;j<=n;j++){
            temp[star[j].F.F][star[j].F.S]+=star[j].S%(c+1);
            star[j].S++;
        }
        for(int j=1;j<=100;j++){
            for(int k=1;k<=100;k++){
                dp[i][j][k]=(temp[j][k]-dp[i][j-1][k-1]+dp[i][j][k-1]+dp[i][j-1][k]);
            }
        }
    }
    while(q--){
        cin>>t>>x>>y>>u>>v;
        t%=(c+1);
        Ti=dp[t][u][v]+dp[t][x-1][y-1]-dp[t][u][y-1]-dp[t][x-1][v];
        cout<<Ti<<endl;
    }
	return 0;
}
