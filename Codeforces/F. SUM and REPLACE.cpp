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
ll n,Ti=0,BIT[300005]={0},divisor[1000005]={0},t,u,v,q;
set<ll> pos;
void update(int idx,ll val){
    while(idx<=n){
        BIT[idx]+=val;
        idx+=idx&(-idx);
    }
}
ll get(int idx){
    ll res=0;
    while(idx>0){
        res+=BIT[idx];
        idx-=idx&(-idx);
    }
    return res;
}
ll range(int l,int r){
    return get(r)-get(l-1);
}
int main(){
    ios_base::sync_with_stdio(0);
    up(i,1,1e6){
        for(int j=i;j<=1e6;j+=i) divisor[j]++;
    }
    cin>>n>>q;
    up(i,1,n){
        cin>>t;
        update(i,t);
        if(t>2) pos.insert(i);
    }
    while(q--){
        cin>>t>>u>>v;
        if(t==1){
            auto itr1=pos.lower_bound(u);
            while(itr1!=pos.end()&&*itr1<=v){
                t=*itr1;
                ll temp=range(t,t);
                temp=divisor[temp]-temp;
                update(t,temp);
                temp=range(t,t);
                if(temp<=2) itr1 = pos.erase(itr1);
                else itr1++;
            }
        }
        else{
            Ti=range(u,v);
            cout<<Ti<<endl;
        }
    }
    return 0;
}
