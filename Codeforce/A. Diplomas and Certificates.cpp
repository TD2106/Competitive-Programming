#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll n,k,cer,dip,Ti;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	cer=(n/2)/(k+1)*k;
	dip=(n/2)/(k+1);
	Ti=n-cer-dip;
	cout<<dip<<" "<<cer<<" "<<Ti<<endl;
	return 0;
}
