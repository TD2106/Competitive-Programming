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
#define ins insert
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;

int n,k, a[200010], nxt[200010], cnt;
set<int>::iterator it, it1;

int main()
{
    tc()
    {
        map<int,int> ma;
        set<int> ms,ms1;
        scanf("%d%d",&n,&k);

        cnt = 0;
        up(i,1,n) {
            scanf("%d",&a[i]);
        }
        up(i,n+1,n+n) a[i] = a[i-n];
//        up(i,1,n+n) cout << a[i] << " ";
//        cout << endl;
        down(i,n,1) {
            if (!ma.count(a[i])) ma[a[i]] = n+i;
            nxt[i] = ma[a[i]];
            ma[a[i]] = i;
        }
        up(i,1,n) {
//            for (it = ms.begin();it!=ms.end();it++) cout << *it << " ";
//            cout << endl;
//            for (it1 = ms1.begin();it1!=ms1.end();it1++) cout << *it1 << " ";
//            cout << endl;
            if (ms.count(a[i])) {
                ms1.erase(i);
                ms1.ins(nxt[i]);
                continue;
            }
            if (ms.size() < k) {
                ms1.ins(nxt[i]);
                ms.ins(a[i]);
                cnt++;
            }
            else {
                ms.erase(a[*(--ms1.end())]);
                ms1.erase(--ms1.end());
                ms1.ins(nxt[i]);
                ms.ins(a[i]);
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}
