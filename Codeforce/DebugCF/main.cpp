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
typedef pair<pii,pii> piiii;
int n, m, Ti = 0, r, c, x, y;
char maze[2005][2005] = {0};
bool vis[2005][2005] = {0};
deque<piiii> dq;
void go(int cost, int l, int r, int curR, int curC){
    if(curR <= 0 || curR > n || curC <= 0 || curC > m || l > x || r > y || maze[curR][curC] == '*' || vis[curR][curC]) return;
    if(cost) dq.push_back({{l, r}, {curR, curC}});
    else dq.push_front({{l, r}, {curR, curC}});
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> r >> c >> x >> y;
    up(i, 1, n){
        up(j, 1, m){
            cin >> maze[i][j];
        }
    }
    dq.push_front({{0, 0},{r, c}});
    while(!dq.empty()){
        piiii current = dq.front();
        dq.pop_front();
        if(vis[current.se.fi][current.se.se]) continue;
        //cout << current.se.se.fi << ' ' << current.se.se.se << endl;
        Ti++;
        vis[current.se.fi][current.se.se] = 1;
        go(0, current.fi.fi, current.fi.se, current.se.fi - 1, current.se.se);
        go(0, current.fi.fi, current.fi.se, current.se.fi + 1, current.se.se);
        go(1, current.fi.fi + 1, current.fi.se, current.se.fi, current.se.se - 1);
        go(1, current.fi.fi, current.fi.se + 1, current.se.fi, current.se.se + 1);
    }
    cout << Ti << endl;
    return 0;
}
