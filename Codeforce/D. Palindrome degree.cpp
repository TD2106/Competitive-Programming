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
#define M 10000000007
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
llu r=0,l=0,k=1,Ti=0,dp[5000005]={0};
string s;
int main(){
    ios::sync_with_stdio(false);
    cin>>s;
    for(int i=1;i<=s.size();i++){
        //cout<<s[i-1]-'a'<<endl;
        l=l*33+(s[i-1]-'A');
        r+=(s[i-1]-'A')*k;
        k*=33;
        if(r==l) dp[i]=dp[i/2]+1;
        else dp[i]=0;
        //bug(dp[i]);
        Ti+=dp[i];
    }
    cout<<Ti<<endl;
    return 0;
}



