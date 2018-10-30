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
ll n,Ti=0;
pll tree[4*300000+5],p[300005];
priority_queue< pll,vector<pll>,greater<pll> > pq;
bool used[300005]={0};
pll cmp(const pll& a,const pll& b){
    if(a.fi>b.fi) return a;
    else if(a.fi==b.fi&&a.se<b.se) return a;
    else return b;
}
void build(int id,int l,int r){
    if(l==r){
        tree[id]=p[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id]=cmp(tree[id*2],tree[id*2+1]);
}
pll query(int id,int l,int r,int x,int y){
    if(l>y||r<x){
        return {0LL,0LL};
    }
    if(x<=l&&r<=y) return tree[id];
    int mid=(l+r)/2;
    return cmp(query(id*2,l,mid,x,y),query(id*2+1,mid+1,r,x,y));
}
void del(int id,int l,int r,int idx){
    if(l>r) return;
    if(l==r){
        tree[id]={0LL,0LL};
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) del(id*2,l,mid,idx);
    else del(id*2+1,mid+1,r,idx);
    tree[id]=cmp(tree[id*2],tree[id*2+1]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n) cin>>p[i].fi,p[i].se=i,pq.push(p[i]);
    build(1,1,n);
    while(!pq.empty()){
        pll temp=pq.top(),q;
        pq.pop();
        if(used[temp.se]) continue;
        q=query(1,1,n,temp.se+1,n);
        cout<<temp.fi<<' '<<temp.se<<' '<<q.fi<<' '<<q.se<<endl;
        if(q.fi>temp.fi){
            Ti+=q.fi-temp.fi;
            del(1,1,n,q.se);
            del(1,1,n,temp.se);
            used[q.se]=1;
            used[temp.se]=1;
            cout<<Ti<<endl;
        }
    }
    cout<<Ti<<endl;
    return 0;
}
