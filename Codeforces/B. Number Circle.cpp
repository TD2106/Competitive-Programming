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
int n, a[100005] = {0}, answer[100005] = {0}, index = 1;
bool isPossible = true;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    up(i, 1, n){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i += 2){
        answer[index++] = a[i];
    }
    for(int i = (n / 2) * 2; i > 0; i -= 2){
        answer[index++] = a[i];
    }
    up(i, 1, n){
        if(i == 1){
            isPossible &= answer[i] < answer[n] + answer[i + 1];
        } else if(i == n){
            isPossible &= answer[i] < answer[i - 1] + answer[1];
        } else {
            isPossible &= answer[i] < answer[i - 1] + answer[i + 1];
        }
    }
    if(isPossible){
        cout << "YES\n";
        up(i, 1, n) cout << answer[i] << ' ';
    } else {
        cout << "NO\n";
    }
    return 0;
}
