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

int n, f,maxx,res;
string s;
map<int,int> ma;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
//    fr("in.INP");
//    fw("out.OUT");
    tc()
    {
        cin >> n;
        up(i,1,n) {
            cin >> s >> f;
            ma[f]++;
            v.pb(f);
        }
        sort(v.begin(), v.end());
        maxx = 0;
        rep(i,0,v.size()) {
            if (ma[v[i]] > maxx) {
                maxx = ma[v[i]];
                res = v[i];
            }
        }
        cout << res << endl;
        ma.clear();
        v.clear();
    }

}
