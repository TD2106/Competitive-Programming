#include <bits/stdc++.h>
#define bug(x) cout<<#x<<'='<<x<<'\n'
#define tc() int tc;cin>>tc;for(int _tc=0;_tc<tc;++_tc)
#define up(i,l,r) for(int i=l;i<=r;++i)
#define down(i,r,l) for(int i=r;i>=l;--i)
#define fw(file) freopen(file,"w",stdout)
#define fr(file) freopen(file,"r",stdin)
#define reset(x) memset(x,0,sizeof(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
ll tc,n,a[100005],sum=0,g;
int main()
{
    ios_base::sync_with_stdio(0);
//    fr("in.INP");
//    fw("out.OUT");
    cin>>tc;
    while(tc--){
        cin>>n;
        sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i==1) g=a[i];
            else g=__gcd(g,a[i]);
            sum+=a[i];
        }
        cout<<sum<<" "<<g<<endl;
    }
}
