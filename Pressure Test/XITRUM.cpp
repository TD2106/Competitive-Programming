#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int josephus(int n, int k)
{
    if (n == 1) return 1;
    else return (josephus(n - 1, k) + k-1) % n + 1;
}
int main(){
	ios_base::sync_with_stdio(0);
	fr("XITRUM.INP");
	fw("XITRUM.OUT");
	int n,k;
	cin>>n>>k;
	cout<<josephus(n,k)<<endl;
	return 0;
}
