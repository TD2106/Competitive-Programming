#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,a[205];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<2*n;i++) cin>>a[i];
	sort(a,a+2*n);
	if(a[n-1]<a[n]) cout<<"YES";
	else cout<<"NO";
	return 0;
}
