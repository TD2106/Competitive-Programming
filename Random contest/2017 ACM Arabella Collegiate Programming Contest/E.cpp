#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int tc,n;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>tc;
	while(tc--){
        cin>>n;
        if(n==1||n>=4) cout<<"first\n";
        else cout<<"second\n";
	}
	return 0;
}
