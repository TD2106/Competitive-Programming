#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll m,l=1,r=1e18,Ti=-1,mid;
ll check(ll mid){
    ll ways=0;
    for(ll k=2;k*k*k<=mid;k++) ways+=mid/(k*k*k);
    return ways;
}
int main(){
    cin>>m;
    while(l<=r){
        mid=(l+r)/2;
        ll temp=check(mid);
        if(temp==m) Ti=mid;
        if(temp>=m) r=mid-1;
        else l=mid+1;
    }
    cout<<Ti<<endl;
    return 0;
}
