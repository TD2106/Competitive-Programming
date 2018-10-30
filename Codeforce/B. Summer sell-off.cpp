#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define F first
#define S second
using namespace std;
typedef long long int ll;
pair<ll,ll> info[100005];
ll n,Ti=0,f,c=0;
ll cus(pair<ll,ll> a){
    ll c;
    if(a.S>=a.F*2) c=a.F;
    else c=max(0LL,a.S-a.F);
    return c;
}
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    return (cus(a)>cus(b));
}
int main(){
    cin>>n>>f;
    for(int i=0;i<n;i++) cin>>info[i].first>>info[i].second;
    sort(info,info+n,cmp);
    for(int i=0;i<n;i++){
        if(c<f){
            if(info[i].S>=info[i].F*2) Ti+=2*info[i].F;
            else Ti+=info[i].S;
            c++;
        }
        else Ti+=min(info[i].F,info[i].S);
    }
    cout<<Ti<<endl;
	return 0;
}
