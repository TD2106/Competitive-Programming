#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
ll q,h,s,d,n,Ti=0,temp;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>q>>h>>s>>d>>n;
	if(n%2){
        temp=min(q*4,min(h*2,s));
        //cout<<temp<<endl;
        Ti=min(n*4*q,min(n*2*h,min(n*s,n/2*d+temp)));
	}
	else{
        Ti=min(n*4*q,min(n*2*h,min(n*s,n/2*d)));
	}
	cout<<Ti<<endl;
	return 0;
}
