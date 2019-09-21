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
int n, a[1005], ans, cost = 2e9, tempCost;
int costOfTransform(int x, int a){
    if(a == x) return 0;
    else{
        return min(abs(x + 1 - a), abs(x - 1 - a));
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    up(i, 1, n){
        cin >> a[i];
    }
    up(i, 1, 101){
        tempCost = 0;
        up(j, 1, n){
            tempCost += costOfTransform(i, a[j]);
        }
        if(tempCost < cost){
            cost = tempCost;
            ans = i;
        }
    }
    cout << ans << ' ' << cost << endl;
    return 0;
}
