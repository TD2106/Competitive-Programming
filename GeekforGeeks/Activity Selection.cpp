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
    int n,tc,Ti,mark;
    pii a[1000];
    cin>>tc;
    while(tc--){
        Ti=0;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i].se;
        for(int i=0;i<n;i++) cin>>a[i].fi;
        sort(a,a+n);
        for(int i=0;i<n;i++){
            if(i==0) Ti++,mark=a[i].fi;
            else{
                if(a[i].se>=mark){
                    Ti++;
                    mark=a[i].fi;
                }

            }
        }
        cout<<Ti<<endl;
    }
    return 0;
}



