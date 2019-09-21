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
int x, y, z, a, b, c;
bool isPossible = true;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> x >> y >> z >> a >> b >> c;
    if(a < x) isPossible = false;
    a -= x;
    if(a + b < y) isPossible = false;
    if(a + b + c - y < z) isPossible = false;
    if(isPossible) cout << "YES\n";
    else cout <<"NO\n";
    return 0;
}
