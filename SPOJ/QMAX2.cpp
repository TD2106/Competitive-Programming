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
typedef pair<ll,ll> pll;
pll tree[200005];
int n,a[50005],q,xx,yy,type,m;
ll v,Ti;
void build(int id,int l,int r){
    if(l==r){
        tree[id].fi=a[l];
        tree[id].se=0;
        return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id]=max(tree[id*2],tree[id*2+1]);
}
void upd(int id,ll val){
    tree[id].fi+=val;
    tree[id].se+=val;
}
void shiftDown(int id,int l,int r){
    int mid=(l+r)/2;
    upd(id*2,tree[id].se);
    upd(id*2+1,tree[id].se);
    tree[id].se=0;
}
void increaseRange(int id,int l,int r,int x,int y,ll val){
    if(x>r||y<r) return;
    if(x<=l&&r<=y){
        upd(id,v);
        return;
    }
    shiftDown(id,l,r);
    int mid=(l+r)/2;
    increaseRange(id*2,l,mid,x,y,v);
    increaseRange(id*2+1,mid+1,r,x,y,v);
    tree[id].fi=max(tree[id*2].fi,tree[id*2+1].fi);
}
ll query(int id,int l,int r,int x,int y){
    if(x>r||y<l) return 0;
    if(x<=l&&r<=y) return tree[id].fi;
    int mid=(l+r)/2;
    shiftDown(id,l,r);
    return max(query(id*2,l,mid,x,y),query(id*2+1,mid+1,r,x,y));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    up(i,1,n) a[i]=0;
    build(1,1,n);
    while(m--){
        cin>>xx>>yy>>v;
        increaseRange(1,1,n,xx,yy,v);
    }
    cin>>q;
    while(q--){
        cin>>xx>>yy;
        Ti=query(1,1,n,xx,yy);
        cout<<Ti<<endl;
    }
    return 0;
}
