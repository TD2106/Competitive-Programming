#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <functional>
using namespace std;
#define MAX 100
double PI = 2 * acos (0.0);

int main()
{
	//freopen("INPUT.INP", "rt", stdin);
	int T, count = 1;
	scanf("%d", &T);
	double r;
	while(T--)
	{
		scanf("%lf", &r);
		double Area_Square = (2*r)*(2*r);
		double Area_Circle = PI*r*r;
		double res = Area_Square - Area_Circle;
		printf("Case %d: %.2lf\n", count++, res);
	}
	return 0;
}