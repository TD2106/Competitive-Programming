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
typedef pair<int, pii> piii;
int n, m, k, dsu[100005] = {0}, x, ans, p;
set<int> specialVertices, numberOfComponents;
piii edges[100005];
void initDSU(){
    up(i, 1, n) dsu[i] = i;
}
int findDSU(int u){
    return u == dsu[u] ? u : dsu[u] = findDSU(dsu[u]);
}
void unionDSU(int u, int v){
    u = findDSU(u);
    v = findDSU(v);
    if(u != v){
        if(specialVertices.count(v)) swap(u, v);
        dsu[v] = u;
        if(specialVertices.count(u) && specialVertices.count(v)){
            p--;
        }
        //cout << u << ' ' << v << ' ' << p << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    initDSU();
    p = k;
    up(i, 1, k){
        cin >> x;
        specialVertices.insert(x);
    }
    up(i, 1, m){
        cin >> edges[i].se.fi >> edges[i].se.se >> edges[i].fi;
    }
    sort(edges + 1, edges + 1 + m);
    up(i, 1, m){
        if(findDSU(edges[i].se.fi) != findDSU(edges[i].se.se)){
            unionDSU(edges[i].se.fi, edges[i].se.se);
        }
        if(p == 1){
            ans = edges[i].fi;
            break;
        }
    }
    up(i, 1, k) cout << ans << ' ';
    return 0;
}
