#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(0);
	ll a,b,Ti=1;
	cin>>a>>b;
	for(ll i=1;i<=min(a,b);i++) Ti*=i;
	cout<<Ti<<endl;
	return 0;
}
