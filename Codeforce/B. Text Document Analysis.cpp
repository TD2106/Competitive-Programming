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
    int t1=0,t2=0,i,j,temp,n;
    cin>>n>>s;
    s+='_';
    //cout<<s[6]<<" "<<s[7]<<endl;
    for(i=0;i<n;i++){
        if(s[i]=='('){
            j=i;
            while(s[j]!=')'&&j<n){
                if((s[j]=='_'||s[j]=='(')&&(s[j+1]!='_'&&s[j+1]!=')')) t2++;
                //cout<<j<<" "<<t2<<endl;
                j++;
            }
            i=j;
        }
        else{
            temp=0;
            j=i;
            while(s[j]!='('&&j<n){
                if(s[j]!='_') temp++;
                //cout<<j<<" "<<temp<<endl;
                if(s[j]=='_'||j+1==n||s[j+1]=='(') t1=max(t1,temp),temp=0;
                j++;
            }
            i=--j;
        }
    }
    cout<<t1<<" "<<t2<<endl;
    return 0;
}



