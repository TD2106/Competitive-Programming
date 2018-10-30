//Author - Anish Shah
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define sz(c) (int)(c).size()
#define pb push_back
#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)

struct Pt{
    double x, y;
};

double dist(Pt a, Pt b){
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

int main() {
    ios_base::sync_with_stdio(0);
	freopen("COOKIES.INP","r",stdin);
	freopen("COOKIES.OUT","w",stdout);
    vector<Pt> coord;
    Pt p;
    char s[105];
    while(gets(s) && s[0]) {
        sscanf(s, "%lf %lf", &p.x, &p.y);
        coord.pb(p);
    }
    int m = 0;
    REP(i, sz(coord)){
        int c = 0;
        p = coord[i];
        REP(k, sz(coord)){
            if(dist(coord[k], p) <= 2.5+1e-6){
                c++;
            }
        }
        m = max(m, c);
        FOR(j, i+1, sz(coord)-1){
            double q = dist(coord[i], coord[j]);
            if(q <= 5+1e-6){
                double fact = sqrt(6.25-pow(q,2)/4 + 1e-6);
                p.x = (coord[i].x + coord[j].x)/2 + fact*(coord[i].y-coord[j].y)/q;
                p.y = (coord[i].y + coord[j].y)/2 + fact*(coord[j].x-coord[i].x)/q;
                c = 0;
                REP(k, sz(coord)){
                    if(dist(coord[k], p) <= 2.5+1e-6){
                        c++;
                    }
                }
                m = max(m, c);
                p.x = (coord[i].x + coord[j].x)/2 - fact*(coord[i].y-coord[j].y)/q;
                p.y = (coord[i].y + coord[j].y)/2 - fact*(coord[j].x-coord[i].x)/q;
                c = 0;
                REP(k, sz(coord)){
                    if(dist(coord[k], p) <= 2.5+1e-6){
                        c++;
                    }
                }
                m = max(m,c);
            }
        }
    }
    cout << m << endl;
    return 0;
}
