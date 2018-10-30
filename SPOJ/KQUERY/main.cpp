#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<piii,int> piiii;
int tree[120005]={0},a[30005],idx[30005],b[30005]={0},Ti[200005],t;
int n,q,indx;
vector<piiii> queries;
void build(int id,int l,int r){
    if(l==r){
        tree[id] = b[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id]=tree[id*2]+tree[id*2+1];
}
void update(int index,int l,int r,int id){
    if(l==r){
        tree[id]=b[index];
        return;
    }
    int mid=(l+r)/2;
    if(index<=mid) update(index,l,mid,id*2);
    else update(index,mid+1,r,id*2+1);
    tree[id]=tree[id*2]+tree[id*2+1];
}
int query(int x,int y,int l,int r,int id){
    if(x>r||y<l||x>y) return 0;
    else if(x<=l&&r<=y) return tree[id];
    int mid=(l+r)/2;
    return query(x,y,l,mid,2*id)+query(x,y,mid+1,r,2*id+1);
}
bool cmp(int x,int y){
    return a[x]>a[y];
}
int main(){
	ios_base::sync_with_stdio(0);
    //fr("tc.txt");
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        idx[i]=i;
    }
    sort(idx,idx+n,cmp);
    build(1,0,n-1);
    cin>>q;
    //cout<<q<<endl;
    for(int i=0;i<q;i++){
        piiii temp;
        cin>>temp.F.S.F>>temp.F.S.S>>temp.F.F;
        temp.S=i;
        queries.push_back(temp);
    }
    sort(queries.begin(),queries.end(),greater<piiii>());
    indx=0;
    for(int i=0;i<queries.size();i++){
        t=queries[i].F.F;
        while(a[idx[indx]]>t&&indx<n){
            b[idx[indx]]++;
            update(idx[indx],0,n-1,1);
            indx++;
        }
        Ti[queries[i].S]=query(queries[i].F.S.F-1,queries[i].F.S.S-1,0,n-1,1);
    }
    for(int i=0;i<q;i++) cout<<Ti[i]<<endl;
	return 0;
}
