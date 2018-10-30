#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
ll a,b,Ti=1;
int main(){
	ios_base::sync_with_stdio(0);
	fr("BLOCKGAME.INP");
	fw("BLOCKGAME.OUT");
	cin>>a>>b;
	if(a<b) swap(a,b);
	while(a%b!=0){
        if(a/b>1) break;
        a%=b;
        swap(a,b);
        Ti++;
	}
	if(Ti%2) cout<<"win";
	else cout<<"lose";
	return 0;
}
