#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,Ti;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	Ti=n/3*2+bool(n%3);
	cout<<Ti<<endl;
	return 0;
}
