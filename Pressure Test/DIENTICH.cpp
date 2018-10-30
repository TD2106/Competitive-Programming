#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
double pi=2*acos(0.0),Ti,r;
string Loan;
stringstream ss;
int main(){
	//ios_base::sync_with_stdio(0);
	fr("DIENTICH.INP");
	fw("DIENTICH.OUT");
	int tc;
	cin>>tc;
	for(int i=1;i<=tc;i++){
        cin>>r;
        Ti=(4.0*r*r)-pi*r*r;
        cout<<"Case "<<i<<": "<<fixed<<setprecision(2)<<Ti<<endl;
       /* double rounded_down = floor(Ti * 100) / 100;
        double rounded_up = ceil(Ti * 100) / 100;
        if(rounded_up-Ti>0.004) cout<<"Case "<<i<<": "<<fixed<<setprecision(2)<<rounded_down<<endl;
        else cout<<"Case "<<i<<": "<<fixed<<setprecision(2)<<rounded_up<<endl;*/
	}
	return 0;
}
