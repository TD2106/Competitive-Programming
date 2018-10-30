#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
int n,u,v,dp[100005]={0},q,t1,t2,Ti;
vi pos;
int main(){
	ios_base::sync_with_stdio(0);
//	fr("RAITIEN.INP");
//	fw("RAITIEN.OUT");
	cin>>n>>q;
	pos.pb(0);
	for(int i=0;i<n;i++){
        cin>>t1;
        pos.pb(t1);
	}
	sort(all(pos));
	for(int i=1;i<pos.size();i++){
        t1=lower_bound(all(pos),pos[i])-pos.begin();
        dp[t1]++;
	}
	for(int i=1;i<=n;i++) dp[i]+=dp[i-1];
	while(q--){
        cin>>u>>v;
        t1=lower_bound(all(pos),u)-pos.begin()-1;
        t2=upper_bound(all(pos),v)-pos.begin()-1;
        Ti=dp[t2]-dp[t1];
        cout<<Ti<<endl;
	}
	return 0;
}
