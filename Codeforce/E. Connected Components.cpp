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
vector<vi> notAdj;
int n,m,u,v,sz;
vi Ti;
set<int> vertex;
void dfs(int x){
    vertex.erase(x);
    sz++;
    for(int i = 0; i < notAdj[x].size() - 1; ++i) {
        int a = notAdj[x][i], b = notAdj[x][i + 1];
        while(!vertex.empty()) {
            auto it = vertex.upper_bound(a);
            if(it == end(vertex)) break;
            if(*it >= b) break;
            dfs(*it);
        }
   }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    notAdj.resize(n+1);
    up(i,1,m){
        cin>>u>>v;
        notAdj[u].pb(v);
        notAdj[v].pb(u);
    }
    up(i,1,n){
        notAdj[i].pb(0);
        notAdj[i].pb(n+1);
        sort(all(notAdj[i]));
        vertex.insert(i);
    }
    up(i,1,n){
        if(!(vertex.find(i)==vertex.end())){
            sz=0;
            dfs(i);
            Ti.pb(sz);
        }
    }
    sort(all(Ti));
    cout<<Ti.size()<<endl;
    for(int i:Ti) cout<<i<<' ';
    return 0;
}
