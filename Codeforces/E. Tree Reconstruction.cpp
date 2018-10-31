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
int n, cnt[1005] ={0}, toBeConnected, sum = 0, lastUnused = 1, cur = 1;
pii maxIndicesBetweenEdge[1005], ans[1005];
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    toBeConnected = n;
    up(i, 1, n - 1){
        cin >> maxIndicesBetweenEdge[i].fi >> maxIndicesBetweenEdge[i].se;
        cnt[maxIndicesBetweenEdge[i].fi]++;
        if(maxIndicesBetweenEdge[i].se != n || cnt[maxIndicesBetweenEdge[i].fi] > maxIndicesBetweenEdge[i].fi){
            cout << "NO\n";
            return 0;
        }
    }
    up(i, 1, n){
        sum += cnt[i];
        if(sum > i){
            cout << "NO\n";
            return 0;
        }
    }
    up(i, 1, n - 1){
        if(cnt[i] != 0){
            up(j, 1, cnt[i] - 1){
                while(cnt[lastUnused] != 0) lastUnused++;
                cnt[lastUnused] = 1;
                ans[cur].fi = lastUnused;
                ans[cur].se = toBeConnected;
                toBeConnected = lastUnused;
                lastUnused++;
                cur++;
            }
            ans[cur].fi = i;
            ans[cur].se = toBeConnected;
            cur++;
            toBeConnected = n;
        }
    }
    cout << "YES\n";
    up(i, 1, n - 1){
        cout << ans[i].fi << ' ' << ans[i].se << endl;
    }
    return 0;
}
