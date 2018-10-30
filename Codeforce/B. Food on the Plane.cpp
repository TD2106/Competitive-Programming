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

int main(){
    ll r,ans=0;
    char seat;
    cin>>r>>seat;
    ans+=((r-1)/4)*16;
    if(r%2==0) ans+=7;
    if(seat=='f') ans+=1;
    else if(seat=='e') ans+=2;
    else if(seat=='d') ans+=3;
    else if(seat=='a') ans+=4;
    else if(seat=='b') ans+=5;
    else ans+=6;
    cout<<ans<<endl;
    return 0;
}



