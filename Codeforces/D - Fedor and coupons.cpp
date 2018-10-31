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
ll n,k,Ti=0,l;
pair<pll,ll> cou[300005];
priority_queue< ll,vll,greater<ll> > r;
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>cou[i].fi.fi>>cou[i].fi.se;
        cou[i].se=i+1;
    }
    sort(cou,cou+n);
    for(int i=0;i<n;i++){
        r.push(cou[i].fi.se);
        //bug(r.top());
        if(r.size()>k) r.pop();
        if(r.size()==k){
            if(r.top()-cou[i].fi.fi+1>Ti){
                Ti=r.top()-cou[i].fi.fi+1;
                l=cou[i].first.first;
            }
        }
    }
    if(Ti==0){
        cout<<0<<endl;
        for(int i=1;i<=k;i++) cout<<i<<" ";
    }
    else{
        cout<<Ti<<endl;
        for(int i=0;i<n&&k;i++){
            if(cou[i].fi.fi<=l&&cou[i].fi.se>=l+Ti-1) cout<<cou[i].se<<" ",k--;
        }
    }
    return 0;
}



