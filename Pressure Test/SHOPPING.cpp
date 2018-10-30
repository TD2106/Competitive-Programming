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
typedef pair<ll,int> pli;
vi tree[M*4];
pli a[M];
int n,q,xx,yy,temp;
ll Ti,originalA[M],v;
void build(int id,int l,int r){
    if(l==r){
        tree[id].pb(a[l].se);
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id].resize(tree[id*2].size()+tree[id*2+1].size());
    merge(all(tree[id*2]),all(tree[id*2+1]),tree[id].begin());
}
int query(int id,int l,int r,int x,int y,int val){
    if(x>y) return M;
    if(x>r||y<l) return M;
    if(x<=l&&r<=y){
        auto itr=lower_bound(all(tree[id]),val);
        if(itr==tree[id].end()) return M;
        else return *itr;
    }
    int mid=(l+r)/2;
    return min(query(id*2,l,mid,x,y,val),query(id*2+1,mid+1,r,x,y,val));
}
int main(){
    ios_base::sync_with_stdio(0);
//    fr("SHOPPING.INP");
//    fw("SHOPPING.OUT");
    cin>>n>>q;
    up(i,1,n){
        cin>>a[i].fi;
        originalA[i]=a[i].fi;
        a[i].se=i;
    }
    sort(a+1,a+1+n);
    build(1,1,n);
    while(q--){
        cin>>v>>xx>>yy;
        temp=lower_bound(a+1,a+1+n,mp(v+1,0))-(a+1);
        xx=query(1,1,n,1,temp,xx);
        while(xx<=yy&&v!=0){
            v%=originalA[xx];
            temp=lower_bound(a+1,a+1+n,mp(v+1,0))-(a+1);
            xx=query(1,1,n,1,temp,xx+1);
        }
        cout<<v<<endl;
    }
    return 0;
}
