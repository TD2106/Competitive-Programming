#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;
ll between(pll a,ll x){
    return (a.S/x-(a.F-1)/x);
}
ll total(pll a){
    return a.S-a.F+1;
}
ll n,i,j,p,l,r,ways;
pll flower[200005];
double Ti=0,proba;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>p;
	for(i=1;i<=n;i++) cin>>flower[i].F>>flower[i].S;
	for(i=1;i<=n;i++){
        if(i==n) j=1;
        else j=i+1;
        proba=(total(flower[i])-between(flower[i],p))*(total(flower[j])-between(flower[j],p));
        proba/=(1.0*total(flower[i])*total(flower[j]));
        Ti+=2000-2000*proba;
	}
	cout<<fixed<<setprecision(6)<<Ti<<endl;
	return 0;
}
