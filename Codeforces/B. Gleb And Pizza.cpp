#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,Ti=0;
double r,d,x,y,smallR,dis;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>r>>d>>n;
	for(int i=1;i<=n;i++){
        cin>>x>>y>>smallR;
        dis=sqrt(x*x+y*y);
        if(dis+smallR<=r&&dis-smallR>=r-d) Ti++;
	}
	cout<<Ti<<endl;
	return 0;
}
