#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
char city[1005][1005]={0};
int n,m;
pair<int,int> home;
bool vis[1005][1005][5]={0};
void dfs(int r,int c,int turn,int dir){
   // cout<<r<<" "<<c<<" "<<turn<<" "<<dir<<endl;
    if(turn>2) return;
    if(vis[r][c][turn]) return;
    if(city[r][c]!='T'&&city[r][c]!='.'&&city[r][c]!='S') return;
   // cout<<123<<endl;
    if(city[r][c]=='T'&&turn<=2){
        cout<<"YES\n";
        exit(0);
    }
    vis[r][c][turn]=1;
   // cout<<123<<endl;
    if(r==home.first&&c==home.second){
        dfs(r,c+1,0,1);
        dfs(r-1,c,0,2);
        dfs(r,c-1,0,3);
        dfs(r+1,c,0,4);
    }
    else{
       // cout<<123<<endl;
        int temp[5]={0};
        for(int i=1;i<5;i++){
            if(i!=dir) temp[i]=1;
            //cout<<i<<endl;
        }
        //cout<<123<<endl;
        dfs(r,c+1,turn+temp[1],1);
        dfs(r-1,c,turn+temp[2],2);
        dfs(r,c-1,turn+temp[3],3);
        dfs(r+1,c,turn+temp[4],4);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>city[i][j];
            if(city[i][j]=='S') home.first=i,home.second=j;
        }
    }
    dfs(home.first,home.second,0,0);
    cout<<"NO"<<endl;
    return 0;
}
