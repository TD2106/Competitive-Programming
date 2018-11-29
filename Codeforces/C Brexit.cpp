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
int c, p, x, l, a, b, currentPartnership[300005] = {0};
bool isLeft[300005] = {0};
vector<vi> adj;
queue<int> q;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> c >> p >> x >> l;
    adj.resize(c + 1);
    up(i, 1, p){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    up(i, 1, c){
        currentPartnership[i] = adj[i].size();
    }
    q.push(l);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        //bug(u);
        if(isLeft[u]) continue;
        isLeft[u] = 1;
        up(i, 0, adj[u].size() - 1){
            int temp = adj[u][i];
            //bug(temp);
            currentPartnership[temp]--;
            //bug(currentPartnership[temp]);
            if(adj[temp].size() - currentPartnership[temp] >= (adj[temp].size() + 1) / 2){
                q.push(temp);
            }
        }
    }
    if(isLeft[x]) cout << "leave\n";
    else cout <<"stay\n";
    return 0;
}
