#include <bits/stdc++.h>
#include <cstdio>
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

char arr[11];
string s;
double t;
int c, n;
vector<pair<string, double> > a;

int main()
{
    tc()
    {
        double res=0;
        a.clear();
        scanf("%d %d", &c, &n);
        a.pb({"JD",1.0});
        up(i,1,c)
        {
            scanf("%s",arr);
            s = arr;
            scanf("%lf",&t);
            a.pb({s,t});
        }
        sort(a.begin(), a.end());
        up(i,1,n)
        {
            scanf("%lf",&t);
            scanf("%s",arr);
            s = arr;
            res += t * (lower_bound(a.begin(), a.end(), mp(s,0.0))->se);
        }
        //printf("%.6f", res);
        cout<<fixed<<setprecision(6)<<res<<endl;
    }

}
