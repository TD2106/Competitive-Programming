#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int xl,yl,xr,yr,t,Ti=0;
int main(){
	ios_base::sync_with_stdio(0);
	fr("DONGCO.INP");
	fw("DONGCO.OUT");
	cin>>xl>>yl>>xr>>yr;
	cin>>t;
	xl=min(xl,t);
	cin>>t;
	yl=min(yl,t);
	cin>>t;
	xr=max(xr,t);
	cin>>t;
	yr=max(yr,t);
	Ti=max(xr-xl,yr-yl);
	Ti*=Ti;
	cout<<Ti<<endl;
	return 0;
}
