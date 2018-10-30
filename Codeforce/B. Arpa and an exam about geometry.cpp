#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<double,double> pdd;
pdd a,b,c,mid;
double A,B,C;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>a.F>>a.S>>b.F>>b.S>>c.F>>c.S;
	mid.F=(a.F+c.F)/2,mid.S=(a.S+c.S)/2;
	A=a.F-c.F,B=a.S-c.S,C=-A*b.F-B*b.S;
	if((A*mid.F+B*mid.S+C==(double)0)&&b!=mid) cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
