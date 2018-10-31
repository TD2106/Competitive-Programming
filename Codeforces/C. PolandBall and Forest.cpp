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
vector< vi > ball;
stack<int> st;
int n,Ti=0;
bool vis[10005]={0};
void dfs(int u){
    st.push(u);
    vis[u]=1;
    for(int i=0;i<ball[u].size();i++){
        if(!vis[ball[u][i]]) dfs(ball[u][i]);
    }
    st.pop();
}
int main(){
    cin>>n;
    ball.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>Ti;
        ball[i].pb(Ti);
        ball[Ti].pb(i);
    }
    Ti=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i),Ti++;
    }
    cout<<Ti<<endl;
    return 0;
}



