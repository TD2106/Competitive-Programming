#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,t,Ti1=0,Ti0=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	while(n--){
        cin>>t;
        if(t) Ti1=max(Ti0+1,Ti1+1);
        else Ti0++;
	}
	cout<<max(Ti1,Ti0)<<endl;
	return 0;
}
