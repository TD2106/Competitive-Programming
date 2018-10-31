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
string pat,act;
map<char,char> check;
int Ti=0;
int main(){
    cin>>pat>>act;
    if(pat==act){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<pat.size();i++){
        if(pat[i]!=act[i]){
            if(check.count(pat[i])==0&&check.count(act[i])==0){
                check[pat[i]]=act[i];
                check[act[i]]=pat[i];
            }
            else{
                if(check[pat[i]]!=act[i]||check[act[i]]!=pat[i]){
                    cout<<-1<<endl;
                    return 0;
                }
            }
        }
        else{
            if(check.count(pat[i])&&check[pat[i]]!=pat[i]){
                cout<<-1<<endl;
                return 0;
            }
            else check[pat[i]]=pat[i];
        }
    }
    map<char,char>::iterator itr;
    for(itr=check.begin();itr!=check.end();itr++){
        if(itr->first!=itr->second){
            Ti++;
            check.erase(itr->second);
        }
    }
    cout<<Ti<<endl;
    for(itr=check.begin();itr!=check.end();itr++){
        if(itr->first!=itr->second){
            cout<<itr->first<<" "<<itr->second<<endl;
        }
    }
    return 0;
}



