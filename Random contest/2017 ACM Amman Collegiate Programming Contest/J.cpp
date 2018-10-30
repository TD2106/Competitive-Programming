#include <bits/stdc++.h>
#define bug(x) cout<<#x<<'='<<x<<'\n'
#define tc() int tc;cin>>tc;for(int _tc=0;_tc<tc;++_tc)
#define up(i,l,r) for(int i=l;i<=r;++i)
#define down(i,r,l) for(int i=r;i>=l;--i)
#define rep(i,l,r) for (int i=l;i<r;i++)
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

string s;
vector<int> v;

bool go(int pos, int len)
{
    if (pos > s.length()-1) return false;
    if (pos == s.length()-1) return true;
    bool ok = false;
    if (s[pos + len + 1] == ' ') {
        ok = go(pos+len+1, len);
        if (ok) return true;
    }
    return ok;
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    fr("in.INP");
//    fw("out.OUT");

    bool ok;
    int tc;
    getline(cin,s);
    stringstream ss;
    ss << s;
    ss >> tc;
    while (tc--)
    {
        getline(cin,s);
        s = " " + s;
        rep(i,1,s.length()) {
            if (s[i] == ' ') v.pb(i);
        }
        s += " ";
        ok = false;
        if (v.size() > 0) {
            rep(i,0,v.size()) {
                ok = go(0,v[i] - 1);
                if (ok) {
                    cout << "YES\n";
                    break;
                }
            }
        }
        if (!ok) cout << "NO\n";
        v.clear();
    }

}
