#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
int n,m;
char r[21],c[21];
bool vis[21][21]={0};
void dfs(int i,int j){
    //cout<<i<<" "<<j<<endl;
    if(i<1||i>n) return;
    if(j<1||j>m) return;
    if(vis[i][j]) return;
    vis[i][j]=1;
    if(r[i]=='>') dfs(i,j+1);
    if(r[i]=='<') dfs(i,j-1);
    if(c[j]=='^') dfs(i-1,j);
    if(c[j]=='v') dfs(i+1,j);
}
bool check(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j]) return 0;
        }
    }
    return 1;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>r[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //cout<<i<<" "<<j<<endl;
            reset(vis);
            dfs(i,j);
            if(!check()){
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
	return 0;
}
