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
int t=0,n,p[200005]={0},Ti=0,cycle=0;
bool b[200005]={0},vis[200005]={0};
void dfs(int st){
    if(vis[st]) return ;
    vis[st]=1;
    dfs(p[st]);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(b[i]) t++;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cycle++;
            dfs(i);
        }
    }
    if(t%2==0) Ti++;
    if(cycle>1) Ti+=cycle;
    cout<<Ti<<endl;
    return 0;
}



