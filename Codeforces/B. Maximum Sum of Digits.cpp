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
ll n, Ti = 0, temp = 0;
ll sumOfDigit(ll x){
    ll result = 0;
    while(x){
        result += x % 10;
        x /= 10;
    }
    return result;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    while(temp <= n){
        Ti = max(Ti, sumOfDigit(temp) + sumOfDigit(n - temp));
        temp = temp * 10 + 9;
    }
    cout << Ti << endl;
    return 0;
}
