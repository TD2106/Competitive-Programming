#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define M 140000
using namespace std;
typedef long long int ll;
int tree[4*M],a[M],level[4*M]={0},n,m,p,b,temp=1;
void build(int id,int l,int r){
    if(l==r){
        tree[id]=a[l];
        level[id]=0;
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    level[id]=level[id*2]+1;
    if(level[id]%2) tree[id]=tree[id*2]|tree[id*2+1];
    else tree[id]=tree[id*2]^tree[id*2+1];
}
void update(int id,int l,int r,int indx,int x){
    if(l==r){
        a[l]=x;
        tree[id]=x;
        return;
    }
    int mid=(l+r)/2;
    if(indx<=mid) update(id*2,l,mid,indx,x);
    else update(id*2+1,mid+1,r,indx,x);
    if(level[id]%2) tree[id]=tree[id*2]|tree[id*2+1];
    else tree[id]=tree[id*2]^tree[id*2+1];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	while(n){
        temp*=2;
        n--;
	}
	n=temp;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	while(m--){
        cin>>p>>b;
        update(1,1,n,p,b);
        cout<<tree[1]<<endl;
	}
	return 0;
}
