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
typedef pair<pll,pll> pllll;
typedef pair<ll,pll> plll;
ll n,par[200005]={0},Ti=0,times=1e18,bOriginal[200005]={0},ansIdx;
plll tree[4*200000+5];
pllll contest[200005];
vector<int> ansIndices;
plll best(const plll& a,const plll& b){
    plll result;
    if(a.fi>b.fi) result=a;
    else if(a.fi<b.fi) result=b;
    else{
        result.fi=a.fi;
        result.se=min(a.se,b.se);
    }
    return result;
}
void update(int id,int l,int r,plll val,int idx){
    if(l==r){
        tree[id]=val;
        return;
    }
    int mid = (l+r)/2;
    if(idx<=mid) update(id*2,l,mid,val,idx);
    else update(id*2+1,mid+1,r,val,idx);
    tree[id]=best(tree[id*2],tree[id*2+1]);
}
plll query(int id,int l,int r,int x,int y){
    if(l>y||r<x) return {0LL,{0LL,0LL}};
    if(x<=l&&r<=y) return tree[id];
    int mid=(l+r)/2;
    return best(query(id*2,l,mid,x,y),query(id*2+1,mid+1,r,x,y));
}
bool cmp(const pllll& a,const pllll &b){
    return (a.fi.se<b.fi.se||(a.fi.se==b.fi.se&&a.fi.fi<b.fi.fi));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n){
        cin>>contest[i].fi.fi>>contest[i].fi.se>>contest[i].se.fi;
        contest[i].se.se=i;
    }
    sort(contest+1,contest+1+n,cmp);
    up(i,1,n) bOriginal[i] = contest[i].fi.se;
    up(i,1,n){
        int j = upper_bound(bOriginal+1,bOriginal+1+n,contest[i].fi.fi) - bOriginal - 1;
//        bug(i);
//        bug(j);
        plll ansQuery;
        ansQuery.fi=ansQuery.se.fi=ansQuery.se.se=0;
        ll t1,t2;
        if(j!=0){
            ansQuery = query(1,1,n,1,j);
            par[contest[i].se.se] = ansQuery.se.se;
            t1=ansQuery.fi+contest[i].se.fi;
            t2=ansQuery.se.fi+(contest[i].fi.se-contest[i].fi.fi);
            if(t1>Ti||(t1==Ti&&t2<times)){
                Ti=t1;
                times=t2;
                ansIdx=contest[i].se.se;
            }
        }
        else{
            t1=contest[i].se.fi;
            t2=(contest[i].fi.se-contest[i].fi.fi);
            if(t1>Ti||(t1==Ti&&t2<times)){
                Ti=t1;
                times=t2;
                ansIdx=contest[i].se.se;
            }
        }
//        bug(t1);
//        bug(t2);
        update(1,1,n,{t1,{t2,contest[i].se.se}},i);
    }
    do{
        ansIndices.pb(ansIdx);
        ansIdx=par[ansIdx];
    }while(ansIdx!=0);
    sort(all(ansIndices));
    cout<<ansIndices.size()<<' '<<Ti<<' '<<times<<endl;
    for(int i:ansIndices) cout<<i<<' ';
    return 0;
}
