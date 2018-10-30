#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
ll Ti=1,c,p,m;
ll fastMul(ll a,ll b){
    a%=m;
    ll res=0;
    while(b){
        res+=a;
        b--;
        a%=m;
        res%=m;
    }
    return res;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>c>>p>>m;
	for(int i=1;i<=p;i++){
        Ti=Ti*c;
        cout<<Ti%m<<endl;
	}
	cout<<Ti%m<<endl;
	return 0;
}
