#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,Timx,Timn;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	Timx=n/7*2;
	if(n-n/7*7>=2) Timx+=2;
	else if(n-n/7*7==1) Timx+=1;
	n-=5;
	if(n>0){
        Timn=n/7*2;
        if(n-n/7*7>=2) Timn+=2;
        else if(n-n/7*7==1) Timn+=1;
	}
	else Timn=0;
    cout<<Timn<<" "<<Timx<<endl;
	return 0;
}
