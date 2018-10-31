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
ll n,k,total=0,t1,t2;
map<ll,ll> cnt;
vector<ll> Ti;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    down(i,63,0) if((n>>i)&1) cnt[i]++;
    if(k<cnt.size()){
        cout<<"No\n";
        return 0;
    }
    auto itr = cnt.end();
    itr--;
    t1=itr->fi;
    t2=itr->se;
    total = cnt.size();
    while(total+t2<=k){
        total+=t2;
        cnt.erase(t1);
        t1--;
        cnt[t1]+=2*t2;
        t2=cnt[t1];
    }
    for(itr = cnt.begin();itr!=cnt.end();itr++){
        up(i,1,itr->se){
            Ti.pb(itr->fi);
        }
    }
    sort(all(Ti),greater<int>());
    while(Ti.size()<k){
        ll temp = Ti.back();
        Ti.pop_back();
        Ti.pb(temp-1);
        Ti.pb(temp-1);
    }
    cout<<"Yes\n";
    for(ll i:Ti) cout<<i<<' ';
    return 0;
}
