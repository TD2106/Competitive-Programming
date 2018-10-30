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
int n,Ti=0,temp=0,a[100005]={0};
bool vis[100005]={0};
vector<vi> adj;
void dfs(int u){
    vis[u]=1;
    if(u!=1) temp++;
    for(int i=0;i<adj[u].size();i++){
        if(!vis[adj[u][i]]){
            dfs(adj[u][i]);
        }
    }
    Ti=max(Ti,temp);
    temp--;
}
int main(){
    cin>>n;
    adj.resize(n+1);
    for(int i=2;i<=n;i++){
        cin>>a[i];
        adj[i].pb(a[i]);
        adj[a[i]].pb(i);
    }
    dfs(1);
    cout<<Ti<<endl;
    return 0;
}



