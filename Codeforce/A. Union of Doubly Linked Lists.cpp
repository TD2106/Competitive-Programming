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
bool vis[105]={0};
vector<vi> linkedLists;
vi l;
pii lr[105];
int n;
void dfs(int x){
    vis[x]=1;
    l.pb(x);
    if(lr[x].fi!=0&&!vis[lr[x].fi]) dfs(lr[x].fi);
    if(lr[x].se!=0&&!vis[lr[x].se]) dfs(lr[x].se);
}
int findFirst(const vi& a){
    for(auto i:a){
        if(lr[i].fi==0) return i;
    }
}
int findLast(const vi& a){
    for(auto i:a){
        if(lr[i].se==0) return i;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n) cin>>lr[i].fi>>lr[i].se;
    up(i,1,n){
        if(!vis[i]){
            l.clear();
            dfs(i);
            linkedLists.pb(l);
        }
    }
    up(i,1,linkedLists.size()-1){
        int t1=findLast(linkedLists[i-1]),t2=findFirst(linkedLists[i]);
        lr[t1].se=t2;
        lr[t2].fi=t1;
    }
    up(i,1,n) cout<<lr[i].fi<<" "<<lr[i].se<<endl;
    return 0;
}
