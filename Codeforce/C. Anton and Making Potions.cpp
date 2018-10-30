#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
ll n,m,k,in,c[200005]={0},a[200005]={0},dp[200005]={0},x,s,total,ans;
int main (){
	/* the algorithm here is binary search and greedy*/
	vpll b;
	vpll::iterator itr;
	vll d;
	vll::iterator itr1;
	pll temp;
	cin>>n>>m>>k>>x>>s;
	ans=total=x*n;
	a[0]=x;
	d.push_back(0);
	for(int i=1;i<=m;i++) cin>>a[i];
	b.push_back(make_pair(0,0));
	for(int i=1;i<=m;i++){
		cin>>temp.first;
		temp.second=i;
		b.push_back(temp);
	}
	sort(b.begin(),b.end());
	for(int i=0;i<=m;i++){
		if(i==0) dp[i]=a[b[i].second];
		else dp[i]=min(dp[i-1],a[b[i].second]);
	}
	for(int i=1;i<=k;i++) cin>>c[i];	
	for(int i=1;i<=k;i++) cin>>in,d.push_back(in);
	temp.second=200005;
	for(int i=k;i>=1;i--){
		if(d[i]>s) continue;
		temp.first=s-d[i];
		itr=upper_bound(b.begin(),b.end(),temp);
		itr--;
		//cout<<c[i]<<" "<<dp[itr-b.begin()]<<endl;
		ans=min(ans,(n-c[i])*(dp[itr-b.begin()]));
	}
	for(int i=m;i>=1;i--){
		if(b[i].first>s) continue;
		itr1=upper_bound(d.begin(),d.end(),s-b[i].first);
		itr1--;
		//cout<<c[itr1-d.begin()]<<" "<<dp[i]<<endl;
		ans=min(ans,(n-c[itr1-d.begin()])*dp[i]);
	}
	//for(int i=0;i<=m;i++) cout<<dp[i]<<endl;
	cout<<ans<<endl;
}
