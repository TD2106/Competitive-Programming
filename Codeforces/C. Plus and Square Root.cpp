#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll x,n,Ti,temp;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	x=2;
	for(ll i=2;i<=n+1;i++){
        temp=i-1;
        Ti=i*i*temp-x/temp;
        cout<<Ti<<endl;
        x=i*temp;
	}
	return 0;
}
