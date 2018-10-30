#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
pii dp[30005];
int n,Ti=0,p,d,haveTreasure[30005]={0};
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>d;
	for(int i=1;i<=n;i++){
        cin>>p;
        haveTreasure[p]++;
	}
	for(int i=1;i<=30000;i++) dp[i].second=-1e9;
	if(haveTreasure[0]&&haveTreasure[d]) dp[d]=mp(2,-d);
	else if(haveTreasure[0]||haveTreasure[d]) dp[d]=mp(1,-d);
	else dp[d]=mp(0,-d);
	for(int i=d;i<=30000;i++){
        int t1=dp[i].first,t2=abs(dp[i].second);
        if(t2==1e9) continue;
        if(t2-1!=0&&i+t2-1<=30000) dp[i+t2-1]=max(dp[i+t2-1],mp(dp[i].first+haveTreasure[i+t2-1],-(t2-1)));
        if(i+t2<=30000) dp[i+t2]=max(dp[i+t2],mp(dp[i].first+haveTreasure[i+t2],-(t2)));
        if(i+t2+1<=30000) dp[i+t2+1]=max(dp[i+t2+1],mp(dp[i].first+haveTreasure[i+t2+1],-(t2+1)));
        Ti=max(Ti,dp[i].first);
	}
	cout<<Ti<<endl;
	return 0;
}
