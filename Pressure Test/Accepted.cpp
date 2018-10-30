#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int a[50],n,s1=0,s2=0,Ti;
int main(){
	ios_base::sync_with_stdio(0);
	fr("ACCEPTED.INP");
	fw("ACCEPTED.OUT");
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n/2;i++) s1+=a[i];
	for(int i=n/2;i<n;i++) s2+=a[i];
	Ti=s2-s1;
	cout<<Ti<<endl;
	return 0;
}
