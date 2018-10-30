
#include<bits/stdc++.h>
using namespace std;

#define TR(v,i) for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
const int N = 800, INF = 1e9;
vector<int> g[N];
int degIn[N], iscc[N], nscc, n, m;
int timed, low[N], d[N];

void enter() {
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		g[u-1].push_back(v-1);
	}
}

stack<int> st;
void dfs(int u) {
	st.push(u); d[u] = low[u] = timed++;
	TR(g[u], v) if(d[*v] == -1)
		dfs(*v), low[u] = min(low[u], low[*v]);
	else
		low[u] = min(low[u], d[*v]);
	if(low[u] == d[u]) {
		int v;
		do {
			v = st.top(); st.pop();
			iscc[v] = nscc;
		} while(u != v);
		++nscc;
	}
	d[u] = INF;
}

void buildSuperGraph() {
	for(int u = 0; u < n; ++u) TR(g[u], v)
		if(iscc[u] != iscc[*v]) ++degIn[iscc[*v]];
}

int main() {
	ios::sync_with_stdio(false);
	enter();
	fill(d, d+n, -1);
	for(int u = 0; u < n; ++u) if(d[u] == -1) dfs(u);
	buildSuperGraph();
	cout << count(degIn, degIn+nscc, 0) << '\n';
	return 0;
}
