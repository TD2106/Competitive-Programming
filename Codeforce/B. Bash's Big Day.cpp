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
ll n,prime[65]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,
109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,
251,257,263,269,271,277,281,283,293,307,311,313};
int main(){
    ll t,res[100005]={0},ans=1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        for(int j=0;j<65&&prime[j]<=t;j++){
            //bug(prime[j]);
            if(t%prime[j]==0)
            ans=max(ans,++res[prime[j]]);
            while(t%prime[j]==0) t/=prime[j];
            //bug(ans);
        }
        if(t!=1) ans=max(ans,++res[t]);
        //bug(ans);
    }
    cout<<ans<<endl;
    return 0;
}



