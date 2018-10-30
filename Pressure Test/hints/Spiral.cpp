#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MN = 1234;
int a[MN][MN], n, x, y, _x, _y;
bool mark[MN][MN];
queue<pair<int, int> > q;
queue<int> qq; // qq is cnt of each step...

const int dx[] = {0, -1, 0, 1, 0};
const int dy[] = {0, 0, 1, 0, -1};

int BFS(int u) {
	q.push(make_pair(_x, _y));
	mark[_x][_y] = true;
	int cnt = 0;
	qq.push(0);
	while(!q.empty()) {
		_x = q.front().first;
		_y = q.front().second;
		cnt = qq.front();
		qq.pop();
		q.pop();
		for (int i = 1; i <= 4; i++) {
			if(__gcd(a[_x + dx[i]][_y + dy[i]], a[_x][_y]) == 1 and !mark[_x + dx[i]][_y + dy[i]]) {
				qq.push(cnt + 1);
				q.push(make_pair(_x + dx[i], _y + dy[i]));
				mark[_x + dx[i]][_y + dy[i]] = true;
				if(a[_x + dx[i]][_y + dy[i]] == y) {
					return cnt + 1;
				}
			}
		}
	}
	return -1;
}

void init(int n) {
	int val = 1;
	int up = 1, down = n, left = 1, right = n;
	while(val <= n*n) {
		for (int i = left; i <= right; ++ i) {
			a[up][i] = val;
			if(val == x) {
				_x = up; _y = i;
			}
			++ val;
		}
		++ up;
		for (int i = up; i <= down; ++ i) {
			a[i][right] = val;
			if(val == x) {
				_x = i; _y = right;
			}
			++ val;
		}
		-- right;
		for (int i = right; i >= left; -- i) {
			a[down][i] = val;
			if(val == x) {
				_x = down; _y = i;
			}
			++ val;
		}
		-- down;
		for (int i = down; i >= up; -- i) {
			a[i][left] = val;
			if(val == x) {
				_x = i; _y = left;
			}
			++ val;
		}
		++ left;
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		cin >> n >> x >> y;
		if(x == y) {
			cout << 0 << endl;
			continue;
		}
		memset(a, 0, sizeof(a));
		memset(mark, false, sizeof(mark));
		init(n);
		while(!q.empty()) q.pop();
		while(!qq.empty()) qq.pop();
		cout << BFS(x) << endl;

	}

	return 0;
}
