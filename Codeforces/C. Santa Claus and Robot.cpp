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
string s;
ll n,prex,prey,curx,cury,Ti=1,dis=0;
int main(){
    cin>>n>>s;
    prex=prey=curx=cury=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='U') cury++;
        else if(s[i]=='D') cury--;
        else if(s[i]=='L') curx--;
        else curx++;
        if(abs(curx-prex)+abs(cury-prey)>dis) dis=abs(curx-prex)+abs(cury-prey);
        else{
            Ti++;
            dis=0;
            prex=curx;
            prey=cury;
            if(s[i]=='U') prey--;
            else if(s[i]=='D') prey++;
            else if(s[i]=='L') prex++;
            else prex--;
        }
    }
    cout<<Ti<<endl;
    return 0;
}



