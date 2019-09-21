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
deque<int> dq;
set<int> intSet;
int n, a, m, ans = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    up(i, 1, n){
        cin >> a;
        if(!intSet.count(a)){
            if(dq.size() == m){
                ans++;
                intSet.erase(dq.front());
                dq.pop_front();
            }
            dq.push_back(a);
            intSet.insert(a);
        }
    }
    cout << ans << endl;
    return 0;
}
