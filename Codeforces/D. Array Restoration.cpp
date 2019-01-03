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
#define MAX 200005
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
int n, q, a[MAX] = {0}, ans[MAX] = {0};
set<int> filledPositions;
vector<vpii> positions;
bool isQPresent = false;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    positions.resize(q + 1);
    up(i, 1, n){
        cin >> a[i];
        isQPresent = (isQPresent | (a[i] == q));
        if(positions[a[i]].size() == 0 || positions[a[i]].back().se != i - 1){
            positions[a[i]].pb({i, i});
        } else {
            positions[a[i]].back().se = i;
        }
    }
    up(i, 1, q){
        up(idx, 0, (int)positions[i].size() - 2){
            auto itr = filledPositions.upper_bound(positions[i][idx].se);
            if(itr != filledPositions.end() && *itr < positions[i][idx + 1].fi){
                cout << "NO\n";
                return 0;
            }
        }
        for(pii p : positions[i]){
            up(j, p.fi, p.se){
                ans[j] = i;
                filledPositions.insert(j);
            }
        }
    }
    for(pii p : positions[0]){
        up(i, p.fi, p.se){
            if(!isQPresent){
                ans[i] = q;
                isQPresent = true;
            } else {
                auto itr = filledPositions.lower_bound(i);
                if(itr == filledPositions.end()) itr--;
                ans[i] = ans[*itr];
            }
            filledPositions.insert(i);
        }
    }
    if(isQPresent){
        cout << "YES\n";
        up(i, 1, n){
            cout << ans[i] << ' ';
        }
    } else {
        cout << "NO\n";
    }
    return 0;
}
