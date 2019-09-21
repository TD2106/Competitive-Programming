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
typedef pair<ll,ll> pll;

ll n, q, a, m, maxValue = -1, operationTillCycle = 0, A, B;
deque<ll> dq;
vector<pll> answersBeforeCycle;

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    up(i, 1, n){
        cin >> a;
        dq.push_back(a);
        maxValue = max(a, maxValue);
    }
    while(dq.front() != maxValue){
        A = dq.front();
        dq.pop_front();
        B = dq.front();
        dq.pop_front();
        if(A > B){
            dq.push_front(A);
            dq.push_back(B);
        } else {
            dq.push_front(B);
            dq.push_back(A);
        }
        operationTillCycle++;
        answersBeforeCycle.push_back(mp(A,B));
    }
    while(q--){
        cin >> m;
        if(m <= operationTillCycle){
            cout << answersBeforeCycle[m - 1].fi << ' ' << answersBeforeCycle[m - 1].se << endl;
        } else {
            m -= operationTillCycle;
            m = (m % (n - 1));
            if(m == 0) m = n - 1;
            cout << maxValue << ' ' << dq[m] << endl;
        }
    }
    return 0;
}
