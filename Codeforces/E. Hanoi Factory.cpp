#include <bits/stdc++.h>
#define up(i,l,r) for(int i=l;i<=r;i++)
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define reset(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define pb push_back
#define ins insert
#define mp make_pair
#define fi first
#define se second
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pll,pll> pllll;
pllll rings[100005];
ll a[100005]={0},Ti=0,dp[100005]={0},tree[4*100005];
int n,index[100005];
bool cmp(const pllll& lhs,const pllll& rhs){
    return (lhs.fi.se>rhs.fi.se||lhs.fi.se==rhs.fi.se&&lhs.fi.fi>rhs.fi.fi);
}
void update(int id,int l,int r,int idx,ll val){
    if(l==r){
        tree[id]=val;
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) update(id*2,l,mid,idx,val);
    else update(id*2+1,mid+1,r,idx,val);
    tree[id]=max(tree[id*2],tree[id*2+1]);
}
ll query(int id,int l,int r,int x,int y){
    if(x>y) return 0;
    if(x>r||y<l) return 0;
    if(x<=l&&r<=y) return tree[id];
    int mid=(l+r)/2;
    return max(query(id*2,l,mid,x,y),query(id*2+1,mid+1,r,x,y));
}
int main(){
    cin>>n;
    up(i,1,n){
        cin>>rings[i].fi.fi>>rings[i].fi.se>>rings[i].se.fi;
        rings[i].se.se=i;
    }
    sort(rings+1,rings+1+n);
    up(i,1,n){
        a[i]=rings[i].fi.fi;
        index[rings[i].se.se]=i;
    }
    sort(rings+1,rings+1+n,cmp);
//    up(i,1,n){
//        cout<<rings[i].fi.fi<<' '<<rings[i].fi.se<<' '<<rings[i].se.fi<<' '<<rings[i].se.se<<endl;
//    }
    up(i,1,n){
        int temp = lower_bound(a+1,a+1+n,rings[i].fi.se) - (a+1);
        dp[i]+=rings[i].se.fi+query(1,1,n,1,temp);
//        cout<<temp<<' '<<query(1,1,n,1,temp)<<' '<<dp[i]<<endl;
        update(1,1,n,index[rings[i].se.se],dp[i]);
        Ti=max(Ti,dp[i]);
    }
    cout<<Ti<<endl;
    return 0;
}



