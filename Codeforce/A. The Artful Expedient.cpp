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
ll n,x[2005],y[2005],Ti=0;
set<ll> cnt;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n) cin>>x[i],cnt.insert(x[i]);
    up(i,1,n) cin>>y[i],cnt.insert(y[i]);
    up(i,1,n){
        up(j,1,n){
            ll temp=x[i]^y[j];
            if(cnt.count(temp)) Ti++;
        }
    }
    if(Ti%2) cout<<"Koyomi";
    else cout<<"Karen";
    return 0;
}
