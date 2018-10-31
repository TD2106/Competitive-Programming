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
bool checkN(pii pos){
    if(pos.se==10000) return true;
    else return false;
}
bool checkS(pii pos){
    if(pos.se==-10000) return true;
    else return false;
}
int main(){
    pii pos=mp(0,10000);
    int len,n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>len>>s;
        if(checkN(pos)&&s[0]!='S'||checkS(pos)&&s[0]!='N'||abs(pos.se)>10000){
            cout<<"NO\n";
            return 0;
        }
        else{
            if(s[0]=='S') pos.se-=len;
            else if(s[0]=='N') pos.se+=len;
        }
    }
    //bug(pos.fi);
    //bug(pos.se);
    if(checkN(pos)) cout<<"YES\n";
    else cout<<"NO\n";
    //system("pause");
    return 0;
}



