#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define F first
#define S second
using namespace std;
typedef long long int ll;
ll n,tc,a,b;
int main(){
	//ios_base::sync_with_stdio(0);
    freopen("PROBLEM.INP","r",stdin);
    freopen("PROBLEM.OUT","w",stdout);
    cin>>tc;
    while(tc--){
        cin>>n>>a>>b;
        cout<<max(0LL,a-b)<<" "<<min(n-b,a)<<endl;
    }
}
