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
ll n,a[1000005]={0},sum[1000005]={0},st=1,en=0,Ti=0,t;
ll cal(ll a){
    return a*(a-1)/2;
}
int main(){

    fr("TRASH.INP");
    fw("TRASH.OUT");
    ios_base::sync_with_stdio(false);
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]+=a[i]+sum[i-1];
    }
    while(st<=n&&en<=n){
        if(sum[en]-sum[st-1]<=t){
            Ti+=en-st+1;
            //cout<<st<<" "<<en<<" "<<Ti<<endl;
            en++;
        }
        else{
            if(en==st) en++,st++;
            else st++;
        }
    }
    cout<<Ti<<endl;
    return 0;
}



