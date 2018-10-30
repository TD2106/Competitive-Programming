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
    ll n,k,a,b,i=0,j,check[2]={0};
    string ans="";
    cin>>n>>k>>a>>b;
    for(int i=0;i<n;i++){
        if(check[0]+check[1]==k){
            if(check[0]==k){
                if(b==0){
                    cout<<"NO\n";
                    return 0;
                }
                else{
                    check[0]--;
                    check[1]++;
                    ans+='B';
                    b--;
                }
            }
            else if(check[1]==k){
                if(a==0){
                    cout<<"NO\n";
                    return 0;
                }
                else{
                    check[1]--;
                    check[0]++;
                    ans+='G';
                    a--;
                }
            }
            else{
                if(a>b){
                    ans+='G',a--;
                    if(ans[i-k]=='B'){
                        check[0]++;
                        check[1]--;
                    }
                }
                else{
                    ans+='B',b--;
                    if(ans[i-k]=='G'){
                        check[0]--;
                        check[1]++;
                    }
                }
            }
        }
        else{
            if(a>b) ans+='G',a--,check[0]++;
            else ans+='B',b--,check[1]++;
        }
    }
    cout<<ans<<endl;
    return 0;
}



