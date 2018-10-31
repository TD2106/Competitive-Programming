#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll n,k;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	if((n/k)%2) cout<<"YES";
	else cout<<"NO";
	return 0;
}
