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
ll s,x1,x2,t1,t2,p,d,Ti=0;
int main(){
    cin>>s>>x1>>x2>>t1>>t2>>p>>d;
    if(t2<=t1){
        cout<<abs(x1-x2)*t2<<endl;
        return 0;
    }
    Ti=abs(x1-x2)*t2;
    if((x1<p&&p<x2)||(x1>p&&p>x2)){

    }
    return 0;
}



