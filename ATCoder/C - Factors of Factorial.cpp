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
map<ll,ll> numprime;
ll n,t,Ti=1;
vll prime;
bool mark[1001]={0};
int main(){
    for(int i=2;i<=1000;i++){
        if(!mark[i]){
            prime.pb(i);
            for(int j=i*i;j<=1000;j+=i) mark[j]=1;
        }
    }
    cin>>n;
    for(ll i=2;i<=n;i++){
        t=i;
        for(int j=0;j<prime.size()&&prime[j]<=t;j++){
            while(t%prime[j]==0){
                t/=prime[j];
                numprime[prime[j]]++;
            }
        }
    }
    map<ll,ll>::iterator itr;
    for(itr=numprime.begin();itr!=numprime.end();itr++){
        Ti*=(itr->second+1)%1000000007;
        Ti%=1000000007;
    }
    cout<<Ti<<endl;
    return 0;
}



