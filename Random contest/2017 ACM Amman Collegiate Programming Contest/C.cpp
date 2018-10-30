#include <bits/stdc++.h>
#define bug(x) cout<<#x<<'='<<x<<'\n'
#define tc() int tc;cin>>tc;for(int _tc=0;_tc<tc;++_tc)
#define up(i,l,r) for(int i=l;i<=r;++i)
#define rep(i,l,r) for (int i=l;i<r;i++)
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

int tc,a,b,c,temp;

int main()
{
    cin>>tc;
    while(tc--){
        cin>>a>>b>>c;
        temp=min(a,min(b,c));
        if(a==temp) cout<<"First\n";
        else if(b==temp) cout<<"Second\n";
        else cout<<"Third\n";
    }
    return 0;
}
