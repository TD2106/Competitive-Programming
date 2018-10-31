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
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define reset(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define pb push_back
#define ins insert
#define mp make_pair
#define fi first
#define se second
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int main(){
    int x1,x2,x3;
    cin>>x1>>x2>>x3;
    if(x1<=x2&&x2<=x3||x3<=x2&&x2<=x1){
        cout<<abs(x2-x1+x3-x2)<<endl;
    }
    else if(x2<=x1&&x1<=x3||x3<=x1&&x1<=x2){
        cout<<abs(x1-x2+x3-x1)<<endl;
    }
    else if(x1<=x3&&x3<=x2||x2<=x3&&x3<=x1){
        cout<<abs(x3-x1+x2-x3)<<endl;
    }
    return 0;
}



