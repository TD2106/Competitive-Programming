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
#define index   ___index
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

int MOD;

struct Matrix {

    int m, n, d[3][3];

    Matrix(int m = 0, int n = 0) {
        this->m = m;
        this->n = n;
        memset(d, 0, sizeof d);
    }

    Matrix operator * (const Matrix &a) const {
        int x = m;
        int y = n;
        int z = a.n;

        Matrix res(x, z);
        REP(i, x) REP(j, y) REP(k, z)
            res.d[i][k] = (res.d[i][k] + 1LL * d[i][j] * a.d[j][k]) % MOD;
        return res;
    }

    Matrix operator ^ (long long k) const {
        Matrix res(n, n);
        Matrix mul = *this;

        REP(i, n) REP(j, n) res.d[i][j] = i == j ? 1 : 0;

        while (k > 0) {
            if (k & 1) res = res * mul;
            mul = mul * mul;
            k >>= 1;
        }
        return res;
    }
};

int getFib(long long k, int mod) {
    MOD = mod;

    Matrix res(1, 2);
    REP(i, 2) res.d[0][i] = i;
    Matrix mul(2, 2);
    mul.d[1][0] = mul.d[0][1] = mul.d[1][1] = 1;
    mul.d[0][0] = 0;

    res = res * (mul ^ k);

    return res.d[0][0];
}

#define MAX   1000100
int val[MAX], sum[MAX], index[MAX];
void solve(long long s, int n, int mod) {
    REP(i, 2) val[i + 1] = getFib(s + i, mod);

    FOR(i, 3, n) {
        val[i] = val[i - 2] + val[i - 1];
        if (val[i] >= mod) val[i] -= mod;
    }

    FOR(i, 1, n) {
        sum[i] = sum[i - 1] + val[i];
        if (sum[i] >= mod) sum[i] -= mod;
    }

    memset(index, -1, sizeof index);
    REP(i, n + 1) {
        if (index[sum[i]] < 0) index[sum[i]] = i;
        else {
            int t = index[sum[i]];
            cout << i - t;
            FOR(j, t + 1, i) cout << " " << s + j - 1;
            cout << endl;
            return;
        }
    }

    assert(false);
}

int main(void) {
#ifdef THEMIS
    freopen("fibseq.inp", "r", stdin);
    freopen("fibseq.out", "w", stdout);
#endif // THEMIS

    int t; cin >> t;
    REP(love, t) {
        int n, mod;
        long long s; cin >> n >> s >> mod;
        solve(s, n, mod);
    }
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
