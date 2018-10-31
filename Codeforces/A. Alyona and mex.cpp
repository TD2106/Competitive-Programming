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

int main(){
    int n,m,l,r,arr[100005]={0},ans=100005;
    cin>>n>>m;
    while(m--){
        cin>>l>>r;
        ans=min(r-l+1,ans);
    }
    for(int i=0;i<n;i++){
        arr[i]=i%ans;
    }
    cout<<ans<<endl;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}



