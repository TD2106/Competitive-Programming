#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define mp make_pair
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
vector<vector<pii> > location;
int Ti,n,m,dp[305][305],t,p;
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=2e9;
        }
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>p;
	location.resize(p+1);
    init();
	for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>t;
            location[t].pb(mp(i,j));
        }
	}
	for(int i=1;i<=p;i++){
        for(int j=0;j<location[i].size();j++){
            if(i==1){
                t = location[i][j].F-1 + location[i][j].S-1;
                dp[location[i][j].F][location[i][j].S]=t;
                continue;
            }
            for(int k=0;k<location[i-1].size();k++){
                t = abs(location[i-1][k].F-location[i][j].F)+abs(location[i-1][k].S-location[i][j].S);
                dp[location[i][j].F][location[i][j].S]=min(dp[location[i][j].F][location[i][j].S],dp[location[i-1][k].F][location[i-1][k].S]+t);
            }
            //cout<<i<<" "<<location[i][j].F<<" "<<location[i][j].S<<" "<<dp[location[i][j].F][location[i][j].S]<<endl;
        }
	}
	Ti=dp[location[p][0].F][location[p][0].S];
	cout<<Ti<<endl;
	return 0;
}
