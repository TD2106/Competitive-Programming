#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define mod 1000000007
using namespace std;
typedef long long int ll;
ll n,Ti=0,a[3*100005],sum=0,t=2;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=n-1;i>=1;i--){
        sum=sum*2+(a[i+1]-a[i])*(t-1);
        Ti+=sum;
        Ti%=mod;
        t*=2;
        t%=mod;
        sum%=mod;
    }
    cout<<Ti<<endl;
	return 0;
}
