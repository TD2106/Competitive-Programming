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
    ll n,m,k,x,y,Ti,mx,mn,temp;
    cin>>n>>m>>k>>x>>y;
    if(n==1){
        mx=k/m;
        if(k%m) mx++;
        mn=k/m;
        Ti=mn;
        k-=mn*m;
        if(y<=k) Ti++;
    }
    else{
        if(k>=m*n) k-=m*n,mx=1,mn=1,Ti=1;
        else{
            mx=1;
            mn=0;
            if((x-1)*m+y<=k) Ti=1;
            else Ti=0;
            k-=m*n;
        }
        if(k>0){
            if(n!=2){
                mx+=k/((n-1)*m);
                if(k%((n-1)*m)) mx++;
            }
            else{
                mx+=k/(2*m);
                if(k%(2*m)) mx++;
            }
            mn+=k/(2*(n-1)*m);
            if(x==1||x==n) Ti=mn;
            else Ti=2*mn-1;
            k-=(mn-1)*2*(n-1)*m;
            if(x==1||x==n){
                if(x==1&&(n-2)*m+y<=k) Ti++;
                if(x==n&&(2*n-3)*m+y<=k) Ti++;
            }
            else{
                k-=(n-x-1)*m;
                if(y<=k) Ti++;
                k-=y;
                k-=(2*x-3)*m;
                if(y<=k) Ti++;
            }
        }
    }
    cout<<mx<<" "<<mn<<" "<<Ti<<endl;
    return 0;
}



