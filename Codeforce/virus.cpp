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

string s;
int nextDiff[3010][3010], ans[20], n, k;

int cal(int p, int q)
{
    int p1,q1,endpoint, cnt = 0, temp;
    p1 = q + 1;
    q1 = q + (q-p+1);
    endpoint = p1;
    if (q1 < s.length()) {
        while (p < endpoint) {
            temp = nextDiff[p][p1];
            if (s[p] != s[p1]) cnt++;
            if (temp == 1) temp = 2;
            p += temp - 1;
            p1 += temp - 1;
            if (cnt > 10) return 20;
            if (p >= endpoint) return cnt;
        }
    }
    else return 20;
}

void preCal()
{
    int temp;
    rep(i,0,s.length()) nextDiff[i][s.length()] = s.length() - i;

    down(j,s.length()-1,0) {
        down(i,j,0) {
            if (s[i] == s[j]) nextDiff[i][j] = nextDiff[i+1][j+1] + 1;
            else nextDiff[i][j] = 1;
        }
    }

    rep(i,0,s.length()) {
        rep(j,i,s.length()) {
            temp = cal(i,j);
            if (temp <= 10) ans[temp] = max(ans[temp], j - i + 1);
        }
    }
    up(i,1,10) {
        ans[i] = max(ans[i],ans[i-1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    fr("VIRUS.INP");
    fw("VIRUS.OUT");
    cin >> n;
    cin >> s;
    preCal();
    up(i,1,n) {
        cin >> k;
        cout << ans[k] << endl;
    }
}
