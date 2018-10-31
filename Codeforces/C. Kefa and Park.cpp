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
ll n,m,u,v,Ti=0;
bool isCat[100005]={0};
bool vis[100005]={0};
vector< vll > tree;
deque<ll> d;
void dfs(ll st,ll cat){
    d.pb(st);
    vis[st]=1;
    if(isCat[st]) cat++;
    else cat=0;
    if(cat<=m){
        for(int i=0;i<tree[st].size();i++){
            if(!vis[tree[st][i]]) dfs(tree[st][i],cat);
        }
        if(tree[st].size()==1&&st!=1) Ti++;
    }
    else cat--;
    vis[st]=0;
    d.pop_back();
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>isCat[i];
    tree.resize(n+1);
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs(1,0);
    cout<<Ti<<endl;
    return 0;
}



