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
ll x,y,a,b,c,ans=0;
int main(){
    cin>>x>>y;
    a=b=c=y;
    //cout<<a<<" "<<b<<" "<<c<<endl;
    while(a!=x||b!=x||c!=x){
        if(a!=x){
            a=min(x,b+c-1);
            ans++;
        }
        if(b!=x){
            b=min(x,a+c-1);
            ans++;
        }
        if(c!=x){
            c=min(x,a+b-1);
            ans++;
        }
    }
    //cout<<a<<" "<<b<<" "<<c<<endl;
    cout<<ans<<endl;
    return 0;
}



