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
#include <ctime>

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
#define tc() int tc; cin >> tc; for(int _tc=0;_tc<tc;_tc++)
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;

/*
 * Code begins here
 */

long a[1000001];
unsigned long long L[1000001];
int main(){

    int t;
    cin >> t;
    while(t--){
        reset(a);
        reset(L);
        long n;
        long k,k1;
        cin>>n>>k>>k1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        //qhd
        //L[t]=1 n U l[i-1,t]=1 hoac L[i-1,t-a[i]]=1 (i-1 la day truoc do))
        L[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=k;j>=a[i];j--){//duyt nguoc neu duyet suoi tat ca thoa m„n
                if(j>=a[i]) L[j]=L[j]+L[j-a[i]];
            }
        }
        if(L[k]>=k1) cout<<"ENOUGH\n";
        else cout<<L[k]<<endl;
    }
	return 0;
}

/*
 * Code ends here
 */


