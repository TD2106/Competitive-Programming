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
    int n,a[101]={0},sum[101]={0},mark=0;
    bool flag=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]) flag=0;
        sum[i]+=a[i]+sum[i-1];
    }
    if(flag) cout<<"NO\n";
    else{
        cout<<"YES\n";
        if(sum[n]!=0) cout<<1<<endl<<1<<" "<<n<<endl;
        else{
            cout<<2<<endl;
            for(int i=1;i<n;i++){
                if(sum[i]-sum[0]!=0){
                    mark=i;
                    break;
                }
            }
            cout<<1<<" "<<mark<<endl;
            cout<<mark+1<<" "<<n<<endl;
        }
    }
    return 0;
}



