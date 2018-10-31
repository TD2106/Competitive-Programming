#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll m,b,x,y,Ti=0;
ll calc(ll u){
    return u*(u+1)/2;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>m>>b;
	b*=m;
	for(x=0;x<=b;x++){
        y=(b-x)/m;
        Ti=max(Ti,calc(y)*(x+1)+calc(x)*(y+1));
	}
	cout<<Ti<<endl;
	return 0;
}
