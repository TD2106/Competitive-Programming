//BFS + Binary Search
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

#define MAX 505

using namespace std;

const int dy[]={-1,0,1,0},dx[]={0,-1,0,1};
int m, n, mat[MAX][MAX], wp[MAX][MAX], mark[MAX][MAX], wy, wx;

void BFS(int d)
{
	queue<pair<int,int> > q;
	q.push(make_pair(wy,wx));
	mark[wy][wx]=1;
	while (!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();
		for (int i=0; i<4; i++)
		{
			int ny=p.first+dy[i],nx=p.second+dx[i];
			if (ny>=0 && ny<m && nx>=0 && nx<n)
				if (!mark[ny][nx] && abs(mat[p.first][p.second]-mat[ny][nx])<=d)
				{
					q.push(make_pair(ny,nx));
					mark[ny][nx]=1;
				}
		}
	}
}

bool reachable(int d)
{
	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++) mark[i][j]=0;
	BFS(d);
	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			if (wp[i][j] && !mark[i][j])
				return false;
	return true;
}

int main()
{
    fr("OLP.INP");
    fw("OLP.OUT");
	scanf("%d %d", &m, &n);
	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			scanf("%d", &mat[i][j]);
	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
		{
			scanf("%d", &wp[i][j]);
			if (wp[i][j])
			{
				wy = i;
				wx = j;
			}
		}
	// binary search
	int dmin = 0, dmax = 1000000000;
	while(dmin<dmax)
	{
		int d = (dmin+dmax)/2;
		if (reachable(d))
			dmax = d;
		else dmin = d+1;
	}

	printf("%d\n", dmin);
}
