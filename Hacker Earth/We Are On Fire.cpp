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
bool pl[1005][1005]={0};
int n,m,q,u,v,total=0;
void flood(int u,int v){
    if(pl[u][v]){
        pl[u][v]=0;
        total--;
        flood(u+1,v);
        flood(u,v+1);
        flood(u-1,v);
        flood(u,v-1);
    }
    else return ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) {cin>>pl[i][j];if(pl[i][j]) total++;}
    }
    while(q--){
        cin>>u>>v;
        flood(u,v);
        cout<<total<<endl;
    }
    return 0;
}



