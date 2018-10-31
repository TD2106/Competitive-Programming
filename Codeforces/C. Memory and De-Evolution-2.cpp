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
    a=b=c=x;
    //cout<<a<<" "<<b<<" "<<c<<endl;
    while(a!=y||b!=y||c!=y){
        if(a!=y){
            a=max(y,b+1-c);
            ans++;
        }
        if(b!=y){
            b=max(y,a+1-c);
            ans++;
        }
        if(c!=y){
            c=max(y,b+1-a);
            ans++;
        }
        //cout<<a<<" "<<b<<" "<<c<<endl;
    }
    //cout<<a<<" "<<b<<" "<<c<<endl;
    cout<<ans<<endl;
    return 0;
}



