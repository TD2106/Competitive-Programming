#include <bits/stdc++.h>

#define bug(x) cout << #x << " = " << x << endl;
#define fr(a) freopen(a,"r",stdin);
#define fw(a) freopen(a,"w",stdout);
#define tc() int tc;cin >> tc; for (int _tc=1;_tc<=tc;_tc++)
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
typedef unsigned long long int llu;
typedef pair<int,int> ii;

/****************************************************/
void printArr(int a[], int l, int r)
{
    up(i,l,r) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void printMtx(int a[][1010],int n, int m)
{
    up(i,1,n) {
        up(j,1,m) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
/****************************************************/

int a[110],b[110], n;
bool visit[110];

bool check()
{
    up(i,1,n) {
        if (b[i] > a[i]) return true;
        if (b[i] < a[i]) return false;
    }
    return false;
}

void go(int i)
{
    if (i <= n) {
        if (!visit[i]) {
            up(j,a[i],n) {
                if (!visit[j]) {
                    if (j < i && i < b[j]) continue;
                    b[i] = j;
                    b[j] = i;
                    visit[i] = true;
                    visit[j] = true;
                    go(i+1);

                    visit[i] = false;
                    visit[j] = false;
                }
            }
        }
        else go(i+1);
    }
    else {
        if (check()) {
            up(j,1,n) {
                cout << b[j] << " ";
            }
            cout << "\n";
            exit(0);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    memset(visit,false,sizeof(visit));
    cin >> n;
    up(i,1,n) {
        cin >> a[i];
    }
    go(1);
}
