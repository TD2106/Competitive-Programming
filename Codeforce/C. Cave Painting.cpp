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
ll n,k;
set<ll> check;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for(ll i=1;i<=k;i++){
        if(check.count(n%i)){
            cout<<"No";
            return 0;
        }
        check.insert(n%i);
    }
    cout<<"Yes";
    return 0;
}
