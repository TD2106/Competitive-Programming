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
#define M 100000
#define mod 1000000007
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
vector<ll> smallPrime={2,3,5,7,11,13};
void primeFactorization(vector<ll>& v,ll x){
    for(int i=0;i<smallPrime.size();i++){
        ll t=smallPrime[i];
        if(x%t==0){
            while(x%t==0){
                v[i]++;
                x/=t;
            }
        }
    }
}
struct Node{
    ll value;
    vector<ll> prime;
    Node(){
        value=1;
        prime.resize(6);
    };
    void mulValue(ll x){
        value*=x;
        value%=mod;
        primeFactorization(prime,x);
    }
    ll divisor(){
        ll res=1;
        for(ll t:prime){
            res*=(t+1);
            res%=mod;
        }
        return res;
    }
}tree[8*M+5];
Node operator *(const Node a,const Node b){
    Node newNode=Node();
    newNode.value=(a.value*b.value)%mod;
    up(i,0,4){
        newNode.prime[i]=a.prime[i]+b.prime[i];
    }
    return newNode;
}
ll n,u,v,idx=0,q;
bool vis[M+5]={0};
ll a[M+5],aDfs[2*M+5]={0};
string type;
pii euler[M+5];
vector<vi> adj;
Node Ti;
void dfs(int x){
    vis[x]=1;
    aDfs[++idx]=x;
    euler[x].fi=idx;
    for(int i:adj[x]){
        if(!vis[i]){
            dfs(i);
        }
    }
    aDfs[++idx]=x;
    euler[x].se=idx;
}
void build(int id,int l,int r){
    if(l==r){
        tree[id]=Node();
        tree[id].mulValue(aDfs[l]);
//        cout<<l<<" "<<r<<" "<<tree[id].value<<" "<<endl;
//        for(ll t:tree[id].prime) cout<<t<<" ";
//        cout<<endl;
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id]=tree[id*2]*tree[id*2+1];
//    cout<<l<<" "<<r<<" "<<tree[id].value<<endl;
//    for(ll t:tree[id].prime) cout<<t<<" ";
//    cout<<endl;
}
void update(int id,int l,int r,ll val,int index){
    if(l==r){
        tree[id].mulValue(val);
        return;
    }
    int mid=(l+r)/2;
    if(index<=mid) update(id*2,l,mid,val,index);
    else update(id*2+1,mid+1,r,val,index);
    tree[id]=tree[id*2]*tree[id*2+1];
}
Node query(int id,int l,int r,int x,int y){
    if(x>r||y<l){
        Node newNode=Node();
        return newNode;
    }
    else if(x<=l&&r<=y) return tree[id];
    int mid=(l+r)/2;
    return query(id*2,l,mid,x,y)*query(id*2,mid+1,r,x,y);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	adj.resize(n+1);
	up(i,1,n-1){
        cin>>u>>v;
        u++,v++;
        adj[u].pb(v);
        adj[v].pb(u);
	}
    up(i,1,n) cin>>a[i];
	dfs(1);
	up(i,1,idx){
	    ll temp=a[aDfs[i]];
        if(i==euler[aDfs[i]].fi) aDfs[i]=temp;
        else aDfs[i]=1;
    }
//    up(i,1,n){
//        cout<<i<<" "<<euler[i].fi<<" "<<euler[i].se<<endl;
//    }
//    up(i,1,idx) cout<<aDfs[i]<<" ";
//    cout<<endl;
    build(1,1,idx);
    cin>>q;
    while(q--){
        cin>>type;
        if(type=="RAND"){
            cin>>u;
            u++;
            Ti=query(1,1,idx,euler[u].fi,euler[u].se);
            cout<<Ti.value<<" "<<Ti.divisor()<<endl;
        }
        else{
            cin>>u>>v;
            u++;
            update(1,1,idx,v,euler[u].fi);
        }
    }
	return 0;
}
