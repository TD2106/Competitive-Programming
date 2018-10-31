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

int n;
char sign[100010];
ll m[100010];
int main()
{
    ios_base::sync_with_stdio(0);
    tc()
    {
        cin >> n;
        up(i,1,n)
        {
            cin >> m[i] >> sign[i];
            m[i] += 25;
        }

        ll low = 0, up = LLONG_MAX, cur = 0;
        up(i,1,n)
        {
            if(sign[i] == '+')
            {
                cur += m[i];
                low = max(low, cur);
            }
            else
            {
                up = min(up, m[i] + cur);
            }
        }
        cout << up - low << '\n';
    }
}