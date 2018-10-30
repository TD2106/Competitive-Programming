#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;
ll n,k,Ti=0,orderAns[300005];
pair<pll,ll> cost[300005];
set<ll> order;
set<ll>::iterator itr;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
        cin>>cost[i].F.F;
        cost[i].F.S=i;
        order.insert(k+i);
	}
	sort(cost+1,cost+1+n,greater< pair<pll,ll> >());
	for(int i=1;i<=n;i++){
        itr=order.lower_bound(cost[i].F.S);
        cost[i].S=*itr;
        order.erase(*itr);
        Ti+=(cost[i].S-cost[i].F.S)*cost[i].F.F;
        orderAns[cost[i].F.S]=cost[i].S;
	}
	cout<<Ti<<endl;
	for(int i=1;i<=n;i++) cout<<orderAns[i]<<" ";
	return 0;
}
