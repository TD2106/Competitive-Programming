#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
struct Node{
    int val;
    int lazy;
}tree[400005];
int a[100005]={0};
void build(int id,int l,int r){
    if(l==r){
        tree[id].val=a[l];
        tree[id].lazy=0;
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id].val=tree[id*2].val+tree[id*2+1].val;
    tree[id].lazy=0;
}
void upd(int id,int l,int r,int x){
    tree[id].lazy+=x;
    tree[id].val+=(r-l+1)*x;
}
void shiftDown(int id,int l,int r){
    int mid=(l+r)/2;
    upd(id*2,l,mid,tree[id].lazy);
    upd(id*2+1,mid+1,r,tree[id].lazy);
    tree[id].lazy=0;
}
void increaseQuery(int id,int x,int y,int v,int l,int r){
    if(x>r||y<r) return;
    if(x<=l&&r<=y){
        upd(id,l,r,v);
        return;
    }
    shiftDown(id,l,r);
    int mid=(l+r)/2;
    increaseQuery(id*2,x,y,v,l,mid);
    increaseQuery(id*2+1,x,y,v,mid+1,r);
    tree[id].val=tree[id*2].val+tree[id*2+1].val;
}
int sum(int id,int x,int y,int l,int r){
    if(x>l||y<r) return 0;
    if(x<=l&&r<=y) return tree[id].val;
    shiftDown(id,l,r);
    return sum(2*id,x,y,l,(l+r)/2)+sum(id*2+1,x,y,(l+r)/2+1,r);
}
int main(){
	ios_base::sync_with_stdio(0);
	int n,q,x,y,type,v;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	while(q--){
        cin>>type;
        if(type==1){
            cin>>x>>y;
            cout<<sum(1,x,y,1,n)<<endl;
        }
        else{
            cin>>x>>y>>v;
            increaseQuery(1,x,y,v,1,n);
        }
	}
	return 0;
}
