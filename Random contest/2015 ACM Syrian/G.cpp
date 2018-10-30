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

char g[5][400];
int n;
vi xx, yy;
int main()
{
    ios_base::sync_with_stdio(0);
    tc()
    {
        cin >> n;
        xx.clear();
        yy.clear();
        int res = -1;
        up(i,1,3)
        {
            up(j,1,3*n)
            {
                cin >> g[i][j];
                if(g[i][j] == 'X')
                {
                    xx.pb(i);
                    yy.pb(j);
                }
            }
        }
        rep(i,0,xx.size())
        {
            int x = xx[i], y = yy[i];
            int cnt = 0;
            cnt += (g[x-1][y-1] == '*');
            cnt += (g[x][y-1] == '*');
            cnt += (g[x+1][y-1] == '*');
            cnt += (g[x-1][y] == '*');
            cnt += (g[x+1][y] == '*');
            cnt += (g[x-1][y+1] == '*');
            cnt += (g[x][y+1] == '*');
            cnt += (g[x+1][y+1] == '*');

            res = max(res, cnt);
        }
        cout << res*4 << '\n';
    }



}
