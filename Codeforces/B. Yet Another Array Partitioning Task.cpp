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
ll n, m, k, a[M] = {0}, ans = 0, sortedIndex[M];
set<int> biggestMKNumber;
priority_queue<int> pq;
vector<pii> segments;
bool cmp(int x, int y){
    return(a[x] > a[y]);
}
int solveForSegement(int currentSeg, int start){
    int biggestNumFound = 0, lastIndex;
    for(int i = start; n - i >= (k - currentSeg) * m; i++){
        pq.push(a[i]);
        lastIndex = i;
        if(biggestMKNumber.count(i)){
            biggestNumFound++;
        }
        if(biggestNumFound == m){
            break;
        }
    }
    for(int i = 0; !pq.empty(); i++){
        if(i < m){
            ans += pq.top();
        }
        pq.pop();
    }
    segments.pb({start, lastIndex});
    return lastIndex;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    up(i, 1, n){
        cin >> a[i];
        sortedIndex[i] = i;
    }
    sort(sortedIndex + 1, sortedIndex + 1 + n, cmp);
    up(i, 1, m*k){
        biggestMKNumber.insert(sortedIndex[i]);
    }
    int currentSeg = 1, lastIndex = 0;
    while(currentSeg <= k){
        lastIndex = solveForSegement(currentSeg++, lastIndex + 1);
    }
    cout << ans << endl;
    up(i, 0, segments.size() - 2){
        cout << segments[i].se << ' ';
    }
    return 0;
}
