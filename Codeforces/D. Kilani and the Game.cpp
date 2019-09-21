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
typedef pair<pii, int> piii;
int n, m, s[10] = {0}, p, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, ans[10] = {0};
char table[1005][1005];
bool isContinue = true;
queue<pii> q[10];
int getPlayer(char c){
    if(c == '.' || c == '#') return 0;
    else return c - '0';
}
bool isGoable(int i, int j){
    if(i < 1 || j < 1 || i > n || j > m || table[i][j] == '#') return false;
    int currentPlayer = getPlayer(table[i][j]);
    return !currentPlayer;
}
bool bfs(int p){
    up(i, 1, s[p]){
        int qSize = q[p].size();
        if(qSize == 0){
            break;
        }
        while(qSize--){
            pii pos = q[p].front();
            q[p].pop();
            up(j, 0, 3){
                int x = pos.fi + dx[j];
                int y = pos.se + dy[j];
                if(isGoable(x, y)){
                    q[p].push({x, y});
                    ans[p]++;
                    table[x][y] = p + '0';
                }
            }
        }
    }
    return q[p].size();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> p;
    up(i, 1, p){
        cin >> s[i];
    }
    up(i, 1, n){
        up(j, 1, m){
            cin >> table[i][j];
            if(getPlayer(table[i][j])){
                q[getPlayer(table[i][j])].push({i, j});
                ans[getPlayer(table[i][j])]++;
            }
        }
    }
    do{
        isContinue = false;
        up(i, 1, p){
            isContinue |= bfs(i);
        }
    }while(isContinue);
    up(i, 1, p) cout << ans[i] << ' ';
    return 0;
}
