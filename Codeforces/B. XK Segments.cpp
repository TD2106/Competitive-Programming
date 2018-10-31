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
ll n,k,x,Ti=0,a[100005],t1,t2;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>x>>k;
    up(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    up(i,1,n){
        t1=(a[i]+x-1LL)/x;
//        bug(t1);
//        bug((t1+k)*x-1);
//        bug((t1+k-1)*x);
        t2=upper_bound(a+1,a+n+1,(t1+k)*x-1) - lower_bound(a+1,a+n+1,max((t1+k-1)*x,a[i]));
//        bug(t2);
        Ti+=t2;
    }
    cout<<Ti<<endl;
    return 0;
}
