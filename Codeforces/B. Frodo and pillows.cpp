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
    ll n,m,k,Ti,t,l,r,mn,x,mx;
    cin>>n>>m>>k;
    Ti=1;
    m-=n;
    if(m>0){
        l=n-k;
        r=k-1;
        if((int)sqrt(m)>=min(l,r)+1){
            Ti+=min(l,r)+1;
            m-=(min(l,r)+1)*(min(l,r)+1);
            mn=min(l,r);
            mx=max(l,r);
            if(m>0){
                t=(ll)pow(4*mn+3,2)+8*m;
                x=(-(4*mn+3)+(ll)sqrt(t))/2;
                if(x>=0) x=min(x,mx-mn),Ti+=x;
                m-=(x+mn)*(x+mn+1)/2-mn*(mn+1)/2+x*(mn+1);
                if(m>=0) Ti+=m/n;
            }
        }
        else Ti+=(int)sqrt(m);
    }
    cout<<Ti<<endl;
    return 0;
}



