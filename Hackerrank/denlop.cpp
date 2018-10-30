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
ll c,t,l,e,x,Ti,tc;
vector<pll> store,temp;
pll best;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>tc;
    while(tc--){
        cin>>c>>t>>l;
        store.clear();
        store.pb({0LL,0LL});
        Ti=1e18;
        up(i,1,c){
            up(j,1,t){
                cin>>x>>e;
                best.fi=1e18;
                best.se=x;
                for(auto tempP:store){
                    if(tempP.fi+e>=best.fi) break;
                    if(abs(x-tempP.se)+tempP.fi+e<best.fi) best.fi=abs(x-tempP.se)+tempP.fi+e;
                }
                temp.pb(best);
            }
            store=temp;
            sort(all(store));
            temp.clear();
        }
        for(auto tempP:store){
            Ti=min(Ti,abs(l-tempP.se)+tempP.fi);
        }
        cout<<Ti<<endl;
    }
    return 0;
}
