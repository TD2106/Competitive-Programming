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
#define M 200005
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int n, a[M], q, l, r, k, ans = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    up(i, 1, n){
        cin >> a[i];
    }
    while(q--){
        priority_queue<int> pq;
        cin >> l >> r >> k;
        up(i, l, r){
            pq.push(a[i]);
        }
        while(k--){
            ans = pq.top();
            pq.pop();
        }
        cout << ans << endl;
    }
    return 0;
}
