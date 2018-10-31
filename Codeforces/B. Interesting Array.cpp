#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
int n,m,l[100005],r[100005],q[100005],allOne=1073741823,Ti[100005],temp[100005],tree[400005];
void build(int id,int u,int v){
    if(u==v){
        tree[id]=Ti[u];
        return;
    }
    int mid=(u+v)/2;
    build(id*2,u,mid);
    build(id*2+1,mid+1,v);
    tree[id]=tree[id*2]&tree[id*2+1];
}
int query(int id,int x,int y,int u,int v){
    if(x>v||y<u) return allOne;
    else if(x<=u&&v<=y) return tree[id];
    int mid=(u+v)/2;
    return query(id*2,x,y,u,mid)&query(id*2+1,x,y,mid+1,v);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>l[i]>>r[i]>>q[i];
    for(int i=0;i<30;i++){
        reset(temp);
        for(int j=1;j<=m;j++){
            if(q[j]&(1<<i)){
                temp[l[j]]++;
                temp[r[j]+1]--;
            }
        }
        for(int j=1;j<=n;j++) temp[j]+=temp[j-1];
        for(int j=1;j<=n;j++){
            if(temp[j]>0){
                Ti[j]=Ti[j]|(1<<i);
            }
        }
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        if(query(1,l[i],r[i],1,n)!=q[i]){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++) cout<<Ti[i]<<" ";
	return 0;
}
