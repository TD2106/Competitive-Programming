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
int n,m,cost[100005]={0},dsu[100005],u,v;
ll Ti=0;
int find(int x){
    if(x==dsu[x]) return x;
    else return dsu[x]=find(dsu[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    cost[x]=min(cost[x],cost[y]);
    cost[y]=0;
    dsu[y]=x;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    up(i,1,n){
        cin>>cost[i];
        dsu[i]=i;
    }
    up(i,1,m){
        cin>>u>>v;
        merge(u,v);
    }
    up(i,1,n) Ti+=(ll)cost[i];
    cout<<Ti<<endl;
    return 0;
}
