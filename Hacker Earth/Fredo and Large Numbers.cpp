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
#include <unordered_map>
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
unordered_map<int,pii> data;
unordered_map<int,pii>::iterator itr;
vpii a;
vpii::iterator itrv;
int n,t,q,f;
bool cmp(pii a,pii b){
    return (a.fi<b.fi||a.fi==b.fi&&data[a.se].se<data[b.se].se);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        if(data.count(t)==0){
            data[t].fi=1;
            data[t].se=i;
        }
        else data[t].fi++;
    }
    for(itr=data.begin();itr!=data.end();itr++){
        a.pb(mp(itr->se.fi,itr->fi));
    }
    sort(all(a),cmp);
    cin>>q;
    while(q--){
        cin>>t>>f;
        itrv=lower_bound(all(a),mp(f,0));
        cout<<itrv->se<<endl;
    }
    return 0;
}



