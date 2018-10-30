#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
ll n,k,num,idx=0;
string Ti="Impossible";
vector<ll> remain;
ll bSearch(ll x){
    ll l=0,r=1e9,res=0,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(mid*(mid+1)/2>x) r=mid-1;
        else l=mid+1,res=max(res,mid);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    if(n*(n-1)/2<k){
        cout<<Ti<<endl;
        return 0;
    }
    Ti="";
    num=bSearch(k);
    if(num!=0){
        k-=num*(num+1)/2;
        for(int i=1;i<=k/num;i++) remain.pb(num);
        k%=num;
        if(k!=0) remain.pb(k);
        reverse(all(remain));
    }
//    cout<<num<<endl;
//    for(int i:remain) cout<<i<<endl;
//    cout<<remain.size()<<endl;
    up(i,0,num){
        if(remain.size()){
            while(i==remain[idx]&&idx<remain.size()){
                Ti+="()";
                idx++;
            }
        }
        Ti+='(';
    }
    up(i,0,num) Ti+=')';
    while(Ti.size()<2*n) Ti+="()";
    cout<<Ti<<endl;
}
