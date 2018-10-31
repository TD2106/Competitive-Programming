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
    ll n,l[100005]={0},r[100005]={0},suml=0,sumr=0,beau=-1,temp,Ti=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
        suml+=l[i];
        sumr+=r[i];
    }
    beau=abs(suml-sumr);
    for(int i=1;i<=n;i++){
        suml+=r[i]-l[i];
        sumr+=l[i]-r[i];
        temp=abs(suml-sumr);
        if(temp>beau){
            beau=temp;
            Ti=i;
        }
        suml-=r[i]-l[i];
        sumr-=l[i]-r[i];
    }
    cout<<Ti<<endl;
    return 0;
}



