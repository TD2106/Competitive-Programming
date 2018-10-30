#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;
pll tree[400005];
ll a[100005],n,m,w,h,Ti;
void build(int id,int l,int r){
    if(l==r){
        tree[id].F=a[l];
        tree[id].S=0;
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id]=max(tree[id*2],tree[id*2+1]);
}
void upd(int id,ll x){
    tree[id].F=max(tree[id].F,x);
    tree[id].S=max(tree[id].S,x);
}
void shiftDown(int id,int l,int r){
    int mid=(l+r)/2;
    if(l<=mid) upd(id*2,tree[id].S);
    if(mid+1<=r) upd(id*2+1,tree[id].S);
    tree[id].S=0;
}
void update(int id,int l,int r,int x,int y,ll val){
    if(x>r||y<l) return;
    else if(x<=l&&r<=y){
        upd(id,val);
        return;
    }
    shiftDown(id,l,r);
    int mid=(l+r)/2;
    update(id*2,l,mid,x,y,val);
    update(id*2+1,mid+1,r,x,y,val);
    tree[id]=max(tree[id*2],tree[id*2+1]);
}
ll queryMax(int id,int l,int r,int x,int y){
    if(x>r||y<l) return 0;
    else if(x<=l&&r<=y) return tree[id].F;
    shiftDown(id,l,r);
    int mid=(l+r)/2;
    return max(queryMax(id*2,l,mid,x,y),queryMax(id*2+1,mid+1,r,x,y));
}
int main(){
	ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    cin>>m;
    while(m--){
        cin>>w>>h;
        Ti=queryMax(1,1,n,1,w);
        cout<<Ti<<endl;
        update(1,1,n,1,w,Ti+h);
    }
	return 0;
}
