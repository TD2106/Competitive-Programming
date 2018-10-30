#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,k,mx,mn;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	if(k==0) cout<<0<<" "<<0<<endl;
	else if(k==n) cout<<0<<" "<<0<<endl;
	else{
        mn=1;
        mx=min(2*k,n-k);
        cout<<mn<<" "<<mx<<endl;
	}
	return 0;
}
