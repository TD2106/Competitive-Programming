#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll n,Ti=1e9;
ll f(ll a,ll b){
    ll r1=0,r2=0;
    while(a) r1++,a/=10;
    while(b) r2++,b/=10;
    return max(r1,r2);
}
int main(){
    cin>>n;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            Ti=min(Ti,f(i,n/i));
        }
    }
    cout<<Ti<<endl;
    return 0;
}
