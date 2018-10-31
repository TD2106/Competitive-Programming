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
int tc,n,Ti[100005],mod=1e9+7,temp,a[100005]={0};
multiset<int> ms;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>tc;
    while(tc--){
        ms.clear();
        reset(Ti);
        cin>>n;
        up(i,1,n) cin>>a[i],ms.insert(a[i]);
        up(i,1,n){
            auto itr=ms.lower_bound(a[i]);
            ms.erase(itr);
            itr=ms.upper_bound(mod-1-a[i]);
            if(itr!=ms.begin()) itr--;
            Ti[i]=(*itr+a[i])%mod;
            itr=ms.upper_bound(2*mod-1-a[i]);
            if(itr!=ms.begin()) itr--;
            Ti[i]=max(Ti[i],(*itr+a[i])%mod);
            ms.insert(a[i]);
        }
        up(i,1,n) cout<<Ti[i]<<' ';
        cout<<endl;
    }
    return 0;
}
