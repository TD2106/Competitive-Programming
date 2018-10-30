#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll n,l,r,k,BITI[100005],BIT[100005],q,s,type,t,Ti;
void update(ll x,int idx,ll *arr){
    while(idx<=n){
        arr[idx]+=x;
        idx+=idx&-idx;
    }
}
ll query(int idx,ll *arr){
    ll sum=0;
    while(idx>0){
        sum+=arr[idx];
        idx-=idx&-idx;
    }
    return sum;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>t;
        update(t*i,i,BITI);
        update(t,i,BIT);
    }
    while(q--){
        cin>>type;
        if(type==1){
            cin>>k>>l>>r;
            if(!(k>l&&k<r)) Ti=abs(k*(query(r,BIT)-query(l-1,BIT))-(query(r,BITI)-query(l-1,BITI)));
            else{
                Ti=(query(k,BIT)-query(l-1,BIT))*k-(query(k,BITI)-query(l-1,BITI))+(query(r,BITI)-query(k,BITI))-(query(r,BIT)-query(k,BIT))*k;
            }
            cout<<Ti<<endl;
        }
        else{
            cin>>k>>s;
            update(s,k,BIT);
            update(s*k,k,BITI);
        }
    }
	return 0;
}
