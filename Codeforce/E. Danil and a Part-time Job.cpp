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
typedef pair<pii,int> piii;
piii operator + (const piii& a, const piii& b){
    piii temp;
    temp.fi.fi=a.fi.fi+b.fi.fi;
    temp.fi.se=a.fi.se+b.fi.se;
    temp.se=0;
    return temp;
}
int state[200005]={0},n,dfsOrder[400005]={0},idx=0,Ti=0,u,q;
pii euler[200005];
piii tree[4*400005];
string type;
vector<vi> child;
void dfs(int x){
    dfsOrder[++idx]=x;
    euler[x].fi=idx;
    for(int i:child[x]) dfs(i);
    dfsOrder[++idx]=x;
    euler[x].se=idx;
}
void build(int id,int l,int r){
    if(l==r){
        if(euler[dfsOrder[l]].fi==l){
            if(state[dfsOrder[l]]){
                tree[id].fi.fi=1;
                tree[id].fi.se=0;
                tree[id].se=0;
            }
            else{
                tree[id].fi.fi=0;
                tree[id].fi.se=1;
                tree[id].se=0;
            }
        }
//        cout<<id<<' '<<l<<' '<<r<<' '<<tree[id].fi.fi<<' '<<tree[id].fi.se<<endl;
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id]=tree[id*2]+tree[id*2+1];
//    cout<<id<<' '<<l<<' '<<r<<' '<<tree[id].fi.fi<<' '<<tree[id].fi.se<<endl;
}
void upd(int id,int val){
    tree[id].se+=val;
    if(val%2) swap(tree[id].fi.fi,tree[id].fi.se);
}
void shiftDown(int id,int l,int r){
    if(l!=r){
        upd(id*2,tree[id].se);
        upd(id*2+1,tree[id].se);
    }
    tree[id].se=0;
}
void update(int id,int l,int r,int x,int y,int val){
    if(l>y||r<x) return;
    if(x<=l&&r<=y){
        upd(id,val);
        return;
    }
    shiftDown(id,l,r);
    int mid=(l+r)/2;
    update(id*2,l,mid,x,y,val);
    update(id*2+1,mid+1,r,x,y,val);
    tree[id]=tree[id*2]+tree[id*2+1];
}
int query(int id,int l,int r,int x,int y){
    if(l>y||r<x) return 0;
    if(x<=l&&r<=y){
        return tree[id].fi.fi;
    }
    shiftDown(id,l,r);
    int mid=(l+r)/2;
    return query(id*2,l,mid,x,y)+query(id*2+1,mid+1,r,x,y);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    child.resize(n+1);
    up(i,2,n){
        cin>>u;
        child[u].pb(i);
    }
    up(i,1,n) cin>>state[i];
    dfs(1);
////    up(i,1,2*n) cout<<dfsOrder[i]<<' ';
//    cout<<endl;
    build(1,1,2*n);
    cin>>q;
    while(q--){
        cin>>type>>u;
        if(type=="get") cout<<query(1,1,2*n,euler[u].fi,euler[u].se)<<endl;
        else update(1,1,2*n,euler[u].fi,euler[u].se,1);
    }
    return 0;
}
