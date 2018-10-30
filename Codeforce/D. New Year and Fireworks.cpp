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
#include <unordered_set>
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
bool visited[405][405]={0};
bool marking[405][405][35][10]={0};
int n,t[35]={0},Ti=0;
void dfs(int st,int dir,int r,int c){
    if(st==n+1) return;
    if(marking[r][c][st][dir]){
        //bug(r);bug(c);bug(dir);bug(st);
        return ;
    }
    marking[r][c][st][dir]=1;
    if(dir==1){
        for(int i=0;i<t[st];i++) if(!visited[r+i][c]) visited[r+i][c]=1,Ti++;
        dfs(st+1,2,r+t[st],c+1);
        dfs(st+1,3,r+t[st],c-1);
    }
    else if(dir==2){
        for(int i=0;i<t[st];i++) if(!visited[r+i][c+i]) visited[r+i][c+i]=1,Ti++;
        dfs(st+1,1,r+t[st],c+t[st]-1);
        dfs(st+1,4,r+t[st]-1,c+t[st]);
    }
    else if(dir==3){
        for(int i=0;i<t[st];i++) if(!visited[r+i][c-i]) visited[r+i][c-i]=1,Ti++;
        dfs(st+1,1,r+t[st],c-t[st]+1);
        dfs(st+1,5,r+t[st]-1,c-t[st]);
    }
    else if(dir==4){
        for(int i=0;i<t[st];i++) if(!visited[r][c+i]) visited[r][c+i]=1,Ti++;
        dfs(st+1,2,r+1,c+t[st]);
        dfs(st+1,6,r-1,c+t[st]);
    }
    else if(dir==5){
        for(int i=0;i<t[st];i++) if(!visited[r][c-i]) visited[r][c-i]=1,Ti++;
        dfs(st+1,3,r+1,c-t[st]);
        dfs(st+1,7,r-1,c-t[st]);
    }
    else if(dir==6){
        for(int i=0;i<t[st];i++) if(!visited[r-i][c+i]) visited[r-i][c+i]=1,Ti++;
        dfs(st+1,4,r-t[st]+1,c+t[st]);
        dfs(st+1,8,r-t[st],c+t[st]-1);
    }
    else if(dir==7){
        for(int i=0;i<t[st];i++) if(!visited[r-i][c-i]) visited[r-i][c-i]=1,Ti++;
        dfs(st+1,5,r-t[st]+1,c-t[st]);
        dfs(st+1,8,r-t[st],c-t[st]+1);
    }
    else if(dir==8){
        for(int i=0;i<t[st];i++) if(!visited[r-i][c]) visited[r-i][c]=1,Ti++;
        dfs(st+1,6,r-t[st],c+1);
        dfs(st+1,7,r-t[st],c-1);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>t[i];
    dfs(1,1,200,200);
    cout<<Ti<<endl;
    return 0;
}



