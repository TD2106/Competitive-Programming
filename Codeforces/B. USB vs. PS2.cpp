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
ll com[3]={0},m,Ti=0,ti=0;
pll mo[300005];
string s;
int main(){
    cin>>com[0]>>com[1]>>com[2];
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>mo[i].fi>>s;
        if(s=="USB") mo[i].se=0;
        else mo[i].se=1;
    }
    sort(mo,mo+m);
    for(int i=0;i<m;i++){
        if(com[mo[i].se]){
            com[mo[i].se]--;
            ti++;
            Ti+=mo[i].fi;
        }
        else if(com[2]){
            com[2]--;
            ti++;
            Ti+=mo[i].fi;
        }
    }
    cout<<ti<<" "<<Ti<<endl;
    return 0;
}



