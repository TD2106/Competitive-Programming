#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n;
ll a,b,x,y,Ti;
int main(){
	scanf("%d",&n);
	while(n--){
        scanf("%d%d",&a,&b);
        Ti=round(cbrt((long double)a*b));
        x=a/Ti,y=b/Ti;
        if(a%Ti!=0||b%Ti!=0||x*x*y!=a||y*y*x!=b) puts("No\n");
        else puts("Yes\n");

	}
	return 0;
}
