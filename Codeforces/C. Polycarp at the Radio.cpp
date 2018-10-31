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
    int n,m,mn,a[2005]={0},b[2005]={0},idx=0,Ti=0,st=0;
    vi index;
    vpii numsong;
    cin>>n>>m;
    mn=n/m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<=m) b[a[i]]++;
        if(a[i]<=m){
            if(b[a[i]]>mn) index.pb(i);
        }
        if(a[i]>m) index.pb(i);
    }
    for(int i=1;i<=m;i++) numsong.pb(mp(b[i],i));
    sort(all(numsong));
    while(idx<m){
        for(int i=st;i<index.size()&&numsong[idx].fi<mn;i++){
            st=i;
            numsong[idx].fi++;
            a[index[i]]=numsong[idx].se;
            Ti++;
        }
        st++;
        idx++;
    }
    cout<<mn<<" "<<Ti<<endl;
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}



