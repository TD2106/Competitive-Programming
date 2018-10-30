#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
vi tree[800005],adj[100005];
int n,a[100005],idx=0,Ti[100005],temp,dfsOrder[200005];
pii euler[100005];
bool vis[100005]={0};
void dfs(int x){
    euler[x].first=++idx;
    dfsOrder[idx]=x;
    vis[x]=1;
    for(auto i:adj[x]){
        if(!vis[i]){
            dfs(i);
        }
    }
    euler[x].second=++idx;
    dfsOrder[idx]=x;
}
void build(int id,int l,int r){
    if(l==r){
        tree[id].pb(a[dfsOrder[l]]);
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id].resize(tree[id*2].size()+tree[id*2+1].size());
    merge(all(tree[id*2]),all(tree[id*2+1]),tree[id].begin());
}
int query(int x,int y,int id,int l,int r,int val){
    if(x>r||y<l) return 0;
    else if(x<=l&&r<=y){
        return tree[id].end()-upper_bound(all(tree[id]),val);
    }
    int mid=(l+r)/2;
    return query(x,y,id*2,l,mid,val)+query(x,y,id*2+1,mid+1,r,val);
}
int main(){
	ios_base::sync_with_stdio(0);
	fr("STARTUP.INP");
	fw("STARTUP.OUT");
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++){
        cin>>temp;
        adj[i].pb(temp);
        adj[temp].pb(i);
	}
	dfs(1);
	build(1,1,idx);
	for(int i=1;i<=n;i++){
        Ti[i]=query(euler[i].first,euler[i].second,1,1,idx,a[i])/2;
	}
	for(int i=1;i<=n;i++) cout<<Ti[i]<<endl;
}
