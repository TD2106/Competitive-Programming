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
    string s;
    int q,l,r,sum[100005]={0};
    cin>>s;
    if(s[0]==s[1]) sum[2]=1;
    for(int i=1;i<s.size()-1;i++){
        if(s[i]==s[i+1]) sum[i+2]+=1+sum[i-1+2];
        else sum[i+2]=sum[i-1+2];
    }
    //for(int i=0;i<s.size();i++) bug(sum[i]);
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<sum[r]-sum[l]<<endl;
    }
    return 0;
}



