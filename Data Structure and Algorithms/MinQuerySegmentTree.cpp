#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int tree[400005],n,a[100005],q;
char type;
void build(int id,int l,int r){
    if(l==r){
        tree[id]=a[l];
        return;
    }
    else{
        int mid=(l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        tree[id]=min(tree[id*2],tree[id*2+1]);
    }
}
void modify(int idx,int x,int id,int l,int r){
    if(l==r){
        tree[id]=x;
        a[idx]=x;
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) modify(idx,x,id*2,l,mid);
    else modify(idx,x,id*2+1,mid+1,r);
    tree[id]=min(tree[id*2],tree[id*2+1]);
}
int query(int x,int y,int l,int r,int id){
    if(x>r||y<l) return 2e9;
    else if(x<=l&&r<=y) return tree[id];
    else return min(query(x,y,l,(l+r)/2,id*2),query(x,y,(l+r)/2+1,r,id*2+1));
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>q;
	int x,y;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	while(q--){
        cin>>type>>x>>y;
        if(type=='q') cout<<query(x,y,1,n,1)<<endl;
        else modify(x,y,1,1,n);
	}
	return 0;
}
