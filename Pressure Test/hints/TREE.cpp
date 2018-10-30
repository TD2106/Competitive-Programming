#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;

const ll maxn = 1e5+5;
const ll maxint = 1e15+7;

struct ele
{
    ll l, r, val;
} a[maxn];

ll n;

ll DFS (ll index, ll low, ll high)
{
    if (!(low<a[index].val && a[index].val<high)) return 0;
    ll fi = a[index].l ? DFS(a[index].l, low, a[index].val) : 0;
    ll se = a[index].r ? DFS(a[index].r, a[index].val, high) : 0;
    return fi + se + 1;
}

int main()
{
    /*freopen("12.in", "r", stdin);
    freopen("12.ans", "w", stdout);*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%lld", &n);
    for (ll i=1; i<=n; i++)
        scanf("%lld%lld%lld", &a[i].l, &a[i].r, &a[i].val);
    //********************
    ll ans = 1;
    for (ll i=1; i<=n; i++)
    {
        ans = max(ans, DFS(i, -maxint, maxint));
        if (ans==n) break;
    }
    //********************
    printf("%lld\n", ans);
    return 0;
}
