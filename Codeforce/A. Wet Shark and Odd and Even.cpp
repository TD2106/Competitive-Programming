#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
ll Ti=0,minOdd=2e9,temp,n;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	while(n--){
        cin>>temp;
        Ti+=temp;
        if(temp%2) minOdd=min(minOdd,temp);
	}
	if(Ti%2) Ti-=minOdd;
	cout<<Ti<<endl;
	return 0;
}
