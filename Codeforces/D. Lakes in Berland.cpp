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
char ber[55][55]={0};
int n,m,k,Ti;
bool vis[55][55]={0};
vector< pair<int,pii> > lake;
void flood(int r,int c){
    if(ber[r][c]=='.'&&!vis[r][c]){
        Ti++;
        vis[r][c]=1;
        flood(r+1,c);
        flood(r,c+1);
        flood(r-1,c);
        flood(r,c-1);
    }
}
void change(int r,int c){
    if(ber[r][c]=='.'){
        ber[r][c]='*';
        change(r+1,c);
        change(r,c+1);
        change(r-1,c);
        change(r,c-1);
    }
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>ber[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1||i==n||j==1||j==m){
                if(ber[i][j]=='.'&&!vis[i][j]) flood(i,j);
            }
        }
    }
    //cout<<123<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ber[i][j]=='.'&&!vis[i][j]&&(i!=1&&i!=n)&&(j!=1&&j!=m)){
                Ti=0;
                flood(i,j);
                lake.pb(mp(Ti,mp(i,j)));
            }
        }
    }
    sort(all(lake));
    Ti=0;
    for(int i=0;i<lake.size()-k;i++){
        Ti+=lake[i].fi;
        change(lake[i].se.fi,lake[i].se.se);
    }
    cout<<Ti<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cout<<ber[i][j];
        cout<<endl;
    }
    return 0;
}



