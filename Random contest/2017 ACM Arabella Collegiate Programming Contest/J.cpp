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
double pi=3.141592653,l,a,ans;
int tc;
int main()
{
    ios_base::sync_with_stdio(0);
//    fr("in.INP");
//    fw("out.OUT");
    cin>>tc;
    while(tc--){
        cin>>l>>a;
        ans=l*l*pi*a/360-0.5*l*l*sin(pi*a/180);
        cout<<fixed<<setprecision(6)<<ans<<endl;
    }
}
