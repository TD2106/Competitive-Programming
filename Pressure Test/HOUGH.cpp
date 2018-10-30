#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,m,a[100005],b[100005],Ti;
int main(){
	ios_base::sync_with_stdio(0);
	fr("HOUGH.INP");
	fw("HOUGH.OUT");
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	sort(a,a+n);
	for(int i=0;i<m;i++){
        Ti=lower_bound(a,a+n,b[i])-a;
        cout<<Ti<<endl;
	}
	return 0;
}
