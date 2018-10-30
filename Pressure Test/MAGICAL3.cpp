#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
ll n,Ti=1e18;
int main(){
	ios_base::sync_with_stdio(0);
	fr("MAGICAL3.INP");
	fw("MAGICAL3.OUT");
	cin>>n;
	n-=3;
	Ti=n;
	for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            if(i>3) Ti=min(Ti,i);
            if(n/i>3) Ti=min(Ti,n/i);
        }
	}
	cout<<Ti<<endl;
	return 0;
}
