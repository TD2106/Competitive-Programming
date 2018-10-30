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
ll toll(string s){
    ll a;
    stringstream ss;
    ss<<s;
    ss>>a;
    return a;
}
ll digit(ll n){
    ll ans=0;
    while(n) ans++,n/=10;
    return ans;
}
int main(){
    ll n,p,i,j,Ti=0,d;
    string s,temp;
    cin>>n>>s;
    d=digit(n);
    p=1;
    for(i=s.size()-1;i>=0;i--){
        temp.clear();
        for(j=i;j>i-d&&j>=0;j--){
            i=j;
            temp+=s[j];
        }
        reverse(all(temp));
        while(temp[0]=='0'){
            if(temp.size()==1) break;
            else{
                i++;
                temp.erase(0,1);
            }
        }
        if(toll(temp)>=n){
            while(toll(temp)>=n||temp[0]=='0'){
                if(temp.size()==1) break;
                i++;
                temp.erase(0,1);
            }
        }
        Ti+=toll(temp)*p;
        p*=n;
    }
    cout<<Ti<<endl;
    return 0;
}
