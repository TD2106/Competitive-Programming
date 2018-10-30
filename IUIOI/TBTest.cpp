#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
ll n,Ti,k,tc;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>tc;
	while(tc--){
       cin>> n>>k;
	Ti=n;
    while(k--)
    Ti=Ti+Ti%100;
    cout<<Ti<<endl;
	}
	return 0;
}
