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
int Ti=0,n,m,u,v,dsu[2005],degree[2005]={0};
bool vis[2005]={0};
pii dsuInfo[2005];
int find(int x){
    if(x==dsu[x]) return x;
    else return dsu[x]=find(dsu[x]);
}
void join(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    else dsu[x]=y;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    up(i,1,n) dsu[i]=i;
    up(i,1,m){
        cin>>u>>v;
        degree[u]++;
        degree[v]++;
        join(u,v);
    }
    up(i,1,n){
        dsuInfo[find(i)].fi++;
        dsuInfo[find(i)].se+=degree[i];
    }
    up(i,1,n) dsuInfo[i].se/=2;
    up(i,1,n){
        if(dsuInfo[i].fi){
            Ti+=dsuInfo[i].se-(dsuInfo[i].fi-1);
        }
    }
    cout<<Ti<<endl;
    return 0;
}
