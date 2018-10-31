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
int a[500005]={0},n,q,tree[4*500000+5]={0},type,l,r,x,Ti;
void build(int id,int l,int r){
    if(l==r){
        tree[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id]=__gcd(tree[id*2],tree[id*2+1]);
    return;
}
void update(int id,int l,int r,int idx,int val){
    if(l==r){
        tree[id]=val;
        a[l]=val;
        return;
    }
    int mid = (l+r)/2;
    if(idx<=mid) update(id*2,l,mid,idx,val);
    else update(id*2+1,mid+1,r,idx,val);
    tree[id]=__gcd(tree[id*2],tree[id*2+1]);
    return;
}
int query(int id,int l,int r,int x,int y,int val){
    if(x>r||y<l) return 0;
    int mid=(l+r)/2;
    if(x<=l&&r<=y){
        if(tree[id]%val==0) return 0;
        else{
            if(l==r) return 1;
            if(tree[id*2]%val!=0&&tree[id*2+1]%val!=0) return 2;
            else if(tree[id*2]%val!=0) return query(id*2,l,mid,x,y,val);
            else return query(id*2+1,mid+1,r,x,y,val);
        }
    }
    return query(id*2,l,mid,x,y,val)+query(id*2+1,mid+1,r,x,y,val);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n) cin>>a[i];
    build(1,1,n);
    cin>>q;
    while(q--){
        cin>>type;
        if(type==1){
            cin>>l>>r>>x;
            Ti=query(1,1,n,l,r,x);
            if(Ti>=2) cout<<"NO\n";
            else cout<<"YES\n";
        }
        else{
            cin>>l>>x;
            update(1,1,n,l,x);
        }
    }
    return 0;
}
