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
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<pll> vpll;
typedef vector<plll> vplll;
ll n, m, x, c1, c2, t, Ti, l = 1, r = 1e9, allowDistance, dis[10005];
vector<vpll> adj;
bool vis[10005];
void resetDistance(){
    up(i, 1, 10000){
        dis[i] = 1e18;
    }
}
ll dijsktra(ll maxDis){
    reset(vis);
    resetDistance();
    priority_queue< pll, vpll, greater<pll> > pq;
    dis[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        pll u = pq.top();
        pq.pop();
        ll node = u.se;
        if(vis[node]) continue;
        vis[node] = 1;
        for(pll p:adj[node]){
            if(!vis[p.fi] && p.se <= maxDis){
                if(dis[p.fi] > u.fi + p.se){
                    dis[p.fi] = u.fi + p.se;
                    pq.push({dis[p.fi], p.fi});
                }
            }
        }
    }
    return dis[n];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> x;
    adj.resize(n + 1);
    up(i, 1, m){
        cin >> c1 >> c2 >> t;
        adj[c1].pb({c2, t});
        adj[c2].pb({c1, t});
    }
    ll temp = dijsktra(1e9);
    allowDistance = temp * 1.0 / 100 * (100 + x);
    while(l <= r){
        ll mid = (l + r) / 2;
        temp = dijsktra(mid);
        if(temp <= allowDistance){
            Ti = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << Ti << endl;
    return 0;
}
