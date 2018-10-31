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
#define M 200005
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pll,int> plli;
ll n,k,Ti=1e18,index[M]={0},b[M],tree[4*M]={0},dp[M]={0};
plli painter[M];
bool cmp(plli& a,plli& b){
    return (a.fi.se<b.fi.se);
}
void update(int id,int l,int r,int idx,ll v){
    if(l==r){
        tree[id]=max(tree[id],v);
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) update(id*2,l,mid,idx,v);
    else update(id*2+1,mid+1,r,idx,v);
    tree[id]=max(tree[id*2],tree[id*2+1]);
}
ll query(int id,int l,int r,int x,int y){
    if(x>y||x>r||y<l) return 0;
    else if(x<=l&&r<=y) return tree[id];
    int mid=(l+r)/2;
    return max(query(id*2,l,mid,x,y),query(id*2+1,mid+1,r,x,y));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    up(i,1,k){
        cin>>painter[i].fi.fi>>painter[i].fi.se;
        painter[i].se=i;
        b[i]=painter[i].fi.se;
    }
    sort(b+1,b+1+k);
    sort(painter+1,painter+1+k,cmp);
    up(i,1,k) index[painter[i].se]=i;
    sort(painter+1,painter+1+k);
    up(i,1,k){
        int temp = upper_bound(b+1,b+1+k,painter[i].fi.fi) - (b+1);
        dp[i]=query(1,1,k,1,temp)+(painter[i].fi.se-painter[i].fi.fi+1);
        update(1,1,k,index[painter[i].se],dp[i]);
    }
    up(i,1,k) Ti=min(Ti,n-dp[i]);
    cout<<Ti<<endl;
    return 0;
}
