#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll n,l,r,s,mid,Ti;
bool flag=0;
ll sumDigit(ll x){
    ll ans=0;
    while(x) ans+=x%10,x/=10;
    return ans;
}
int main(){
    cin>>n>>s;
    l=1,r=n;
    while(l<=r){
        mid=(l+r)/2;
        if(mid-sumDigit(mid)>=s){
            Ti=mid;
            flag=1;
            r=mid-1;
        }
        else l=mid+1;
    }
    if(flag) cout<<n-Ti+1<<endl;
    else cout<<0<<endl;
	return 0;
}
