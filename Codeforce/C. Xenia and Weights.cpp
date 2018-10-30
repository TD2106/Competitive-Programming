#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
bool vis[1001][21][11]={0},flag=0;
int n,weight[1001]={0};
string s;
void dfs(int times,int diff,int last){
    if(flag) return ;
    if(vis[times][diff][last]) return;
    if(times>n){
        cout<<"YES\n";
        for(int i=1;i<=n;i++) cout<<weight[i]<<" ";
        flag=1;
    }
    else{
        vis[times][diff][last]=1;
        for(int i=diff+1;i<=10;i++){
            if(s[i-1]=='1'&&i!=last){
                weight[times]=i;
                dfs(times+1,i-diff,i);
            }
        }
    }
}
int main(){
    cin>>s>>n;
    dfs(1,0,0);
    if(!flag) cout<<"NO\n";
    return 0;
}
