#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,k,t,Ti;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k>>t;
	if(t<=k) Ti=t;
	else if(t>k&&t<=n) Ti=k;
	else{
        Ti=k;
        t-=n;
        Ti-=t;
	}
	cout<<Ti<<endl;
	return 0;
}
