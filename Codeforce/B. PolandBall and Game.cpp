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
set<string> both,po,ene;
int main(){
    int n,m,sb,spo,se;
    string s;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s;
        po.insert(s);
    }
    for(int i=0;i<m;i++){
        cin>>s;
        if(po.count(s)==0) ene.insert(s);
        else po.erase(s),both.insert(s);
    }
    sb=both.size();
    spo=po.size();
    se=ene.size();
    if(sb%2) se--;
    if(spo<=se) cout<<"NO\n";
    else cout<<"YES\n";
    return 0;
}



