#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }

/* Author: GS.PVH */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   3333
#define MAX_QUERY   13

int nextDiff[MAX][MAX];
int answer[MAX_QUERY];
char s[MAX];
int n, q;

int getAnswer(int l, int r) {
    int len = r - l + 1;
    if (r + len > n) return MAX_QUERY;

    int i = l - 1;
    int j = r;
    int res = 0;
    while (res < MAX_QUERY) {
        int tmp = nextDiff[i][j];
        i += tmp;
        j += tmp;
        if (i > r || j > r + len) break;
        res++;
    }

    return res;
}
void init(void) {
    scanf("%d", &q);
    scanf("%s", s + 1);
    n = strlen(s + 1);

    REP(i, n + 1) nextDiff[i][n] = n + 1;
    FORD(i, n - 1, 0) FORD(j, n - 1, 0)
        nextDiff[i][j] = s[i + 1] == s[j + 1] ? nextDiff[i + 1][j + 1] + 1 : 1;

    FOR(i, 1, n) FOR(j, i, n) {
        int tmp = getAnswer(i, j);

        if (tmp < MAX_QUERY) maximize(answer[tmp], j - i + 1);
    }

    REP(i, MAX_QUERY - 1) maximize(answer[i + 1], answer[i]);
}

void process(void) {
    REP(love, q) {
        int x; scanf("%d", &x);
        printf("%d\n", answer[x]);
    }
}

int main(void) {
#ifdef THEMIS
    freopen("virus.inp", "r", stdin);
    freopen("virus.out", "w", stdout);
#endif // THEMIS

#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY

    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
