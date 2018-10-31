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
char table[15][15]={0};
bool check(){
    bool flag=1;
    for(int i=5;i<9;i++){
        for(int j=5;j<9;j++){
            for(int k=0;k<3;k++) if(table[i+k][j]!='x') flag=0;
            if(flag) return flag;
            flag=1;
            for(int k=0;k<3;k++) if(table[i-k][j]!='x') flag=0;
            if(flag) return flag;
            flag=1;
            for(int k=0;k<3;k++) if(table[i][j+k]!='x') flag=0;
            if(flag) return flag;
            flag=1;
            for(int k=0;k<3;k++) if(table[i][j-k]!='x') flag=0;
            if(flag) return flag;
            flag=1;
            for(int k=0;k<3;k++) if(table[i+k][j+k]!='x') flag=0;
            if(flag) return flag;
            flag=1;
            for(int k=0;k<3;k++) if(table[i-k][j-k]!='x') flag=0;
            if(flag) return flag;
            flag=1;
            for(int k=0;k<3;k++) if(table[i+k][j-k]!='x') flag=0;
            if(flag) return flag;
            flag=1;
            for(int k=0;k<3;k++) if(table[i-k][j+k]!='x') flag=0;
            if(flag) return flag;
            flag=1;
        }
    }
    return 0;
}
int main(){
    for(int i=5;i<9;i++){
        for(int j=5;j<9;j++){
            cin>>table[i][j];
        }
    }
    for(int i=5;i<9;i++){
        for(int j=5;j<9;j++){
            if(table[i][j]=='.'){
                table[i][j]='x';
                if(check()){
                    cout<<"YES\n";
                    return 0;
                }
                table[i][j]='.';
            }
        }
    }
    cout<<"NO\n";
    return 0;
}



