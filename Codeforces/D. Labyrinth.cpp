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
typedef pair<int,piiii> piiiii;
int n, m, Ti = 0, r, c, x, y;
char maze[2005][2005] = {0};
bool vis[2005][2005] = {0};
priority_queue<piiiii, vector<piiiii>, greater<piiiii> > pq;
void go(int totalStep, int l, int r, int curR, int curC){
    if(curR < 0 || curR > n || curC < 0 || curC > m || l > x || r > y || maze[curR][curC] == '*' || vis[curR][curC]) return;
    pq.push({totalStep, {{l, r}, {curR, curR}}});
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> r >> c >> x >> y;
    up(i, 1, n){
        up(j, 1, m){
            cin >> maze[i][j];
        }
    }
    pq.push({0,{{0, 0},{r, c}}});
    while(!pq.empty()){
        Ti++;
        piiiii current = pq.top();
        vis[current.se.se.fi][current.se.se.se] = 1;
        cout << current.first << current.se.se.fi << current.se.se.se << current.se.fi.fi << current.se.fi.se << endl;
        pq.pop();
        go(current.fi, current.se.fi.fi, current.se.fi.se, current.se.se.fi - 1, current.se.se.se);
        go(current.fi, current.se.fi.fi, current.se.fi.se, current.se.se.fi + 1, current.se.se.se);
        go(current.fi + 1, current.se.fi.fi + 1, current.se.fi.se, current.se.se.fi, current.se.se.se - 1);
        go(current.fi + 1, current.se.fi.fi, current.se.fi.se + 1, current.se.se.fi, current.se.se.se + 1);
    }
    cout << Ti << endl;
    return 0;
}
