#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,Tia,Tib;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n&&i<(n-i);i++){
        if(__gcd(i,n-i)==1) Tia=i,Tib=n-i;
	}
	cout<<Tia<<" "<<Tib<<endl;
	return 0;
}
