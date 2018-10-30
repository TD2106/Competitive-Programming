#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
#define fr(a) freopen(a,"r",stdin);
#define fw(a) freopen(a,"w",stdout);
#define tc() int tc;cin >> tc; for(int _tc=1;_tc<=tc;_tc++)
#define up(i,l,r) for (int i=l;i<=r;i++)
#define down(i,r,l) for (int i=r;i>=l;i--)
#define rep(i,l,r) for (int i=l;i<r;i++)
#define pb push_back
#define mp make_pair
#define ins insert
#define fi first
#define se second
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

/****************************************************/
void printArr(int a[], int l, int r)
{ up(i,l,r) cout << a[i] << " \n"[i==r]; }

void printMtx(int a[][1010],int n, int m)
{ up(i,1,n) up(j,1,m) cout << a[i][j] << " \n"[j==m]; }
/****************************************************/

map<string, vi > a;
vector<string> res;

string c, name;
int s,e,v,n;
int main()
{
    ios_base::sync_with_stdio(0);
    tc()
    {
        a.clear();
        res.clear();
        cin >> n;
        up(i,1,n)
        {
            cin >> c >>  s >> e >> v;
            up(j,1,v)
            {
                cin >> name;
                if(!a.count(name))
                {
                    a[name].resize(400);
                }
                a[name][s]++;
                a[name][e+1]--;
            }
        }
        for(auto psv : a)
        {
            bool dup = 0;
            up(i,1,365)
            {
                psv.se[i] += psv.se[i-1];
                if(psv.se[i] > 1)

                {
                    dup = 1;
                    break;
                }
            }
            if(dup) res.pb(psv.fi);
        }
        cout << res.size() << '\n';
        for(string name : res) cout << name << '\n';
    }
}
