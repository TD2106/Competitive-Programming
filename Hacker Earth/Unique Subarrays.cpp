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
map<ll,ll> marking;
ll n,a[100005],tc,st,Ti,t;
int main(){
    cin>>tc;
    while(tc--){
        Ti=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        st=1;
        for(int i=1;i<=n;i++){
            if(marking.count(a[i])==0){
                marking[a[i]]=i;
                t=i-st+1;
                Ti+=t*(t+1)/2;
            }
            else{
                if(st <= marking[a[i]])
                st=marking[a[i]]+1;
                marking[a[i]]=i;
                t=i-st+1;
                Ti+=t*(t+1)/2;
            }
          //  bug(st);
          //  bug(i);
          //  bug(Ti);
        }
        cout<<Ti<<endl;
        marking.clear();
    }
    return 0;
}



