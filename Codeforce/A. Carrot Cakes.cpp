#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    int n,t,k,d,Ti=0;
    cin>>n>>t>>k>>d;
    Ti=(n/k+bool(n%k));
    if(d<(Ti-1)*t) cout<<"YES\n";
    else cout<<"NO\n";
	return 0;
}
