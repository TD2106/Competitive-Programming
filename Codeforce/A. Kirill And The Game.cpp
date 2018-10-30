#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
ll l,r,x,y,k;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>l>>r>>x>>y>>k;
	for(ll i=x;i<=y;i++){
        if(l<=k*i&&k*i<=r){
            cout<<"YES\n";
            return 0;
        }
	}
	cout<<"NO\n";
	return 0;
}
