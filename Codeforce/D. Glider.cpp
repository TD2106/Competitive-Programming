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
int n, h, Ti = 0, lostHeightBetweenRegions[200005] = {0};
pii upwardAirRegions[200005];
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> h;
    up(i, 1, n){
        cin >> upwardAirRegions[i].fi >> upwardAirRegions[i].se;
    }
    sort(upwardAirRegions + 1, upwardAirRegions + 1 + n);
    up(i, 1, n){
        if(i != 1){
            lostHeightBetweenRegions[i - 1] = upwardAirRegions[i].fi - upwardAirRegions[i-1].se;
            lostHeightBetweenRegions[i - 1] += lostHeightBetweenRegions[i - 2];
        }
    }
    int idx1 = 1, idx2 = 1;
    while(idx1 < n && idx2 < n){
        while(lostHeightBetweenRegions[idx2] - lostHeightBetweenRegions[idx1 - 1] < h && idx2 < n) idx2++;
        Ti = max(Ti, upwardAirRegions[idx2].se - upwardAirRegions[idx1].fi + h - (lostHeightBetweenRegions[idx2 - 1] - lostHeightBetweenRegions[idx1 - 1]));
        idx1++;
    }
    if(n == 1){
        Ti = upwardAirRegions[1].se - upwardAirRegions[1].fi + h;
    }
    cout << Ti << endl;
    return 0;
}
