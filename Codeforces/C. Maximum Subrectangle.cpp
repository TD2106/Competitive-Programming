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
int n, m, a[2005] = {0}, b[2005] = {0}, maxLengthForSum[4000005] = {0}, x, Ti = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    up(i, 1, n){
         cin >> a[i];
         a[i] += a[i - 1];
    }
    up(i, 1, m){
        cin >> b[i];
        b[i] += b[i - 1];
    }
    cin >> x;
    up(i, 1, n){
        up(j, i, n){
            maxLengthForSum[a[j] - a[i - 1]] = max(j - i + 1, maxLengthForSum[a[j] - a[i - 1]]);
        }
    }
    up(i, 1, 4000000){
        maxLengthForSum[i] = max(maxLengthForSum[i], maxLengthForSum[i - 1]);
    }
    up(i, 1, m){
        up(j, i, m){
            Ti = max(Ti, (j - i + 1) * maxLengthForSum[min(4000000, x / (b[j] - b[i - 1]))]);
        }
    }
    cout << Ti << endl;
    return 0;
}
