#include <bits/stdc++.h>
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define endl '\n'
#define bug(a) cout<< #a << " = " << a <<endl
#define all(a) a.begin(),a.end()
#define reset(a) memset(a,0,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define tc() int tc;cin>>tc;up(_tc,1,tc)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
int tree[4*100000+5]={0},a[100005]={0},n,q,u,v;
void build(int id,int l,int r){
    if(l==r){
        tree[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id]=max(tree[id*2],tree[id*2+1]);
}
void update(int id,int l,int r,int val,int idx){
    if(l==r){
        tree[id]=val;
        a[idx]=val;
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) update(id*2,l,mid,val,idx);
    else update(id*2+1,mid+1,r,val,idx);
    tree[id] = max(tree[id*2],tree[id*2+1]);
}
int query(int id,int l,int r,int lq,int rq){
    if(l>rq||r<lq) return 0;
    if(lq<=l&&r<=rq) return tree[id];
    int mid=(l+r)/2;
    return max(query(id*2,l,mid,lq,rq),query(id*2+1,mid+1,r,lq,rq));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>q;
    up(i,1,n) cin>>a[i];
    build(1,1,n);
    while(q--){
        cin>>u;
        if(u==1){
            cin>>u>>v;
            cout<<query(1,1,n,u,v)<<endl;
        }
        else{
            cin>>u>>v;
            update(1,1,n,u,v);
        }
    }
    return 0;
}
