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
ll pow2[33]={0},Ti=0,n,t;
map<ll,ll> mark;
int main(){
    cin>>n;
    pow2[0]=1;
    for(int i=1;i<=32;i++) pow2[i]=pow2[i-1]*2;
    for(int i=0;i<n;i++) cin>>t,mark[t]++;
    map<ll,ll>::iterator itr;
    for(itr=mark.begin();itr!=mark.end();itr++){
        for(int i=0;i<=32;i++){
            if(mark.count(pow2[i]-(itr->first))&&pow2[i]-itr->first!=itr->first){
                Ti+=itr->second*mark[pow2[i]-itr->first];
            }
            else if(mark.count(pow2[i]-(itr->first))&&pow2[i]-itr->first==itr->first)
            Ti+=(itr->second-1)*itr->second;
        }
    }
    cout<<Ti/2<<endl;
    return 0;
}



