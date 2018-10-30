#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
ll Ti,c,p,m;
ll fastMul(ll a,ll b){
    a%=m;
    ll res=0;
    while(b){
        if(b%2) res+=a;
        a*=2;
        b/=2;
        a%=m;
        res%=m;
    }
    return res;
}
int main(){
	ios_base::sync_with_stdio(0);
	fr("REMAINDER.INP");
	fw("REMAINDER.OUT");
	cin>>c>>p>>m;
	Ti=c%m;
	for(int i=2;i<=p;i++){
        Ti=fastMul(Ti,c);
        //cout<<Ti<<endl;
	}
	cout<<Ti<<endl;
	return 0;
}
