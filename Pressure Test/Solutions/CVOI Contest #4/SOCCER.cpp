//Geometry, triangle = (1/2) b * h
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
#define MAX 100

double Distance2Points(int x1, int y1, int x2, int y2)
{
	return sqrt((double) (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
}

double DistanceMin(int x1, int y1, int x2, int y2)
{
	double a = Distance2Points(x1, y1, 0, 0);
	double b = Distance2Points(x2, y2, 0, 0);
	double c = Distance2Points(x1, y1, x2, y2);
	double p = (a+b+c)/2;
	double s = sqrt(p*(p-a)*(p-b)*(p-c));
	double h = (2*s)/c;
	return h;
}

int main()
{
    fr("SOCCER.INP");
    fw("SOCCER.OUT");
	//freopen("INPUT.INP","rt",stdin);
    int T;
    scanf("%d", &T);
    for(int t = 1; t<=T; t++)
    {
        int r, n;
        scanf("%d %d", &r, &n);
        int x[MAX];
        int y[MAX];
        for(int i = 0; i<n; i++)
            scanf("%d %d", x+i, y+i);
        bool res = true;
        for(int j = n-1, i = 0; i<n; j=i++)
            if(DistanceMin(x[i], y[i], x[j], y[j]) <= r)
                res = false;
        printf("Case #%d: %s\n", t, res?"NO":"YES");
	}

    return 0;
}
