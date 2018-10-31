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

int main(){
    ios_base::sync_with_stdio(0);
    ll q, x, y, k, Ti, temp;
    cin >> q;
    while(q--){
        cin >> x >> y >> k;
        if(x < y) swap(x,y);
        if(k < x){
            Ti = -1;
        }
        else{
            Ti = y + (x - y) / 2 * 2;
            k -= x;
            temp = k%2;
            Ti += k - temp;
            if(x%2 == y%2 && temp != 0) Ti -= 1;
            else if(x%2 != y%2)Ti += temp;
        }
        cout << Ti << endl;
    }
    return 0;
}
