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
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
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

class DisjointSet {
    private:
    vector<int> lab;

    int find(int x) {
        return lab[x] < 0 ? x : lab[x] = find(lab[x]);
    }

    public:
    DisjointSet(int n = 0) {
        lab.assign(n + 7, -1);
    }

    bool join(int a, int b) {
        int x = find(a);
        int y = find(b);
        if (x == y) return false;
        if (lab[x] > lab[y]) swap(x, y);
        lab[x] += lab[y];
        lab[y] = x;
        return true;
    }
};

struct Edge {
    int u, v, c;
    bool inTree;

    Edge() {
        u = v = c = 0;
        inTree = false;
    }

    void input(void) {
        scanf("%d%d%d", &u, &v, &c);
    }

    int other(int x) const {
        assert(u == x || v == x);
        return u ^ v ^ x;
    }

    bool operator < (const Edge &e) const {
        return c > e.c;
    }
};

#define MAX   100100
#define LOG   17

Edge edges[MAX];
vector<int> adj[MAX];
int par[MAX][LOG + 1], maxEdge[MAX][LOG + 1], high[MAX];
int n, m;

void loadGraph(void) {
    scanf("%d%d", &n, &m);
    REP(i, m) edges[i].input();
}

void buildTree(void) {
    sort(edges, edges + m);

    DisjointSet dsu(n);
    REP(i, m) edges[i].inTree = dsu.join(edges[i].u, edges[i].v);

    REP(i, m) if (edges[i].inTree) {
        adj[edges[i].u].push_back(i);
        adj[edges[i].v].push_back(i);
    }
}

void dfs(int u) {
    FORE(it, adj[u]) {
        int v = edges[*it].other(u);
        if (v != par[u][0]) {
            par[v][0] = u;
            high[v] = high[u] + 1;
            maxEdge[v][0] = edges[*it].c;
            dfs(v);
        }
    }
}
void setupLCA(void) {
    memset(high, -1, sizeof high);
    
    FOR(i, 1, n) if (high[i] < 0) {
    	high[i] = 0;
    	dfs(i);
    }
    
    FOR(j, 1, LOG) FOR(i, 1, n) {
        par[i][j] = par[par[i][j - 1]][j - 1];
        maxEdge[i][j] = max(maxEdge[i][j - 1], maxEdge[par[i][j - 1]][j - 1]);
    }
}

int getMaxEdge(int u, int v) {
    if (high[v] > high[u]) return getMaxEdge(v, u);

    int res = -1;
    FORD(i, LOG, 0) if (high[par[u][i]] >= high[v]) {
        maximize(res, maxEdge[u][i]);
        u = par[u][i];
    }

    if (u == v) return res;
    FORD(i, LOG, 0) if (par[u][i] != par[v][i]) {
        maximize(res, maxEdge[u][i]);
        maximize(res, maxEdge[v][i]);
        u = par[u][i];
        v = par[v][i];
    }

    maximize(res, maxEdge[u][0]);
    maximize(res, maxEdge[v][0]);
    return res;
}

void process(void) {
    int res = 0;
    REP(i, m) if (!edges[i].inTree) maximize(res, edges[i].c + getMaxEdge(edges[i].u, edges[i].v));
    printf("%d\n", res);
}

int main(void) {
	fr("BGAME.INP");
	fw("BGAME.OUT");

    loadGraph();
    buildTree();
    setupLCA();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
