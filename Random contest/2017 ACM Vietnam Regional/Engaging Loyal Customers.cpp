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
#define MAX 50000
#define N 1005
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int n, m, k, K, w[N][N] = {0}, ax[N] = {0}, ay[N] = {0}, match[N] = {0}, u, v, ans = 0;
bool visitX[N], visitY[N];
vector<pii> guestPresent;
bool dfs(int x){
	visitX[x] = true;
	up(i, 1, K){
		int temp = ax[x] + ay[i] - w[x][i];
		if(!visitY[i] && temp == 0){
			visitY[i] = 1;
			if(match[i] < 0 || dfs(match[i]))
				return match[i] = x, 1;
		}
	}
	return 0;
}

void HugarianMatching(){
	up(i, 1, K){
        up(j, 1, K){
            ax[i] = max(ax[i], w[i][j]);
        }
	}
	up(i, 1, K){
		while(!dfs(i)){
			int delta = MAX;
			up(j, 1, K){
                if(!visitY[j]){
                    up(k, 1, K){
                        if(visitX[k]){
                            delta = min(delta, ax[k] + ay[j] - w[k][j]);
                        }
                    }
                }
			}
			up(j, 1, K) if(visitX[j]) ax[j] -= delta, visitX[j] = 0;
			up(j, 1, K) if(visitY[j]) ay[j] += delta, visitY[j] = 0;
		}
	}
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> m >> n >> k;
    K = max(m, n);
    up(i, 1, k){
        cin >> u >> v >> w[u][v];
        w[u][v] = -w[u][v];
    }
    up(i, n + 1, K){
        up(j, 1, K){
            w[i][j] = MAX;
        }
    }
    up(i, m + 1, K){
        up(j, 1, K){
            w[j][i] = MAX;
        }
    }
    HugarianMatching();
    up(i, 1 , K){
        if(match[i] && w[match[i]][i] != -MAX){
            ans += w[match[i]][i];
        }
    }
    cout << ans << endl;
    return 0;
}
