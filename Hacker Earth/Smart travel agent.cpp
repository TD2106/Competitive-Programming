#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;
int adj[101][101]={0},n,r,c1,c2,w,src,des,people,Ti=0;
bool vis[101]={0};
vector<int> temp,ans;
void dfs(int start,int best){
    vis[start]=1;
    temp.push_back(start);
    if(best<Ti){
        temp.pop_back();
        vis[start]=0;
        return;
    }
    if(start==des){
        if(best>Ti){
            ans=temp;
            Ti=best;
        }
        vis[start] = 0;
        temp.pop_back();
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]||adj[start][i]==0) continue;
        dfs(i,min(best,adj[start][i]));
    }
    vis[start] = 0;
    temp.pop_back();
}
int main(){
    cin>>n>>r;
    for(int i=1;i<=r;i++){
        cin>>c1>>c2>>w;
        adj[c1][c2]=w;
        adj[c2][c1]=w;
    }
    cin>>src>>des>>people;
    if(src==des){
        cout<<src<<endl;
        cout<<0<<endl;
        return 0;
    }
    dfs(src,1e9);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
    if(people%(Ti-1)) cout<<people/(Ti-1)+1<<endl;
    else cout<<people/(Ti-1)<<endl;
}



