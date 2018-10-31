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
    string s;
    int Ti=1000000;
    map<char,int> check;
    cin>>s;
    for(int i=0;i<s.size();i++){
        check[s[i]]++;
    }
    Ti=min(Ti,check['B']);
    Ti=min(Ti,check['u']/2);
    Ti=min(Ti,check['b']);
    Ti=min(Ti,check['a']/2);
    Ti=min(Ti,check['s']);
    Ti=min(Ti,check['r']);
    Ti=min(Ti,check['l']);
    cout<<Ti<<endl;
    return 0;
}



