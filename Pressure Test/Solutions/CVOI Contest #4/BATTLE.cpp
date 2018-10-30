//Maximum bipartite matching
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <ctime>
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
using namespace std;

#define FOR(i,a,b) for(int i=int(a);i<=int(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)

bool e[210][210], coverX[210], visY[210];
int matchY[210], m, n;

int find(int x) {
	REP(y, m) if (e[x][y] == 1 && !visY[y]) {
		visY[y] = 1;
		if (matchY[y] == -1 || find(matchY[y])) {
			matchY[y] = x;
			return 1;
		}
	}
	return 0;
}

int main() {
    fr("BATTLE.INP");
    fw("BATTLE.OUT");

	int tN;
	scanf("%d", &tN);
	FOR(cN, 1, tN) {
		memset(e, 0, sizeof(e));
		memset(coverX, 0, sizeof(coverX));
		memset(matchY, -1, sizeof(matchY));
		scanf("%d%d", &m, &n);
		REP(u, n) {
			int deg, v;
			scanf("%d", &deg);
			while (deg--) {
				scanf("%d", &v);
				--v;
				e[u][v] = 1;
			}
		}
		int ans = 0;
		REP(u, n) if (!coverX[u]) {
			memset(visY, 0, sizeof(visY));
			coverX[u] = find(u);
			ans += coverX[u];
		}
		printf("Battle %d: %d\n", cN, ans);
	}
}
