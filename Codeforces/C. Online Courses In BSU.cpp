#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define pb push_back
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
vector<vi> adj;
vi mainCourse,course;
int n,k,t,x,Ti=0,vis[100005]={0};
void dfs(int u){
    if(vis[u]==2) return;
    vis[u]=1;
    Ti++;
    for(int i=0;i<adj[u].size();i++){
        if(vis[adj[u][i]]==1){
            cout<<-1<<endl;
            exit(0);
        }
        else dfs(adj[u][i]);
    }
    course.pb(u);
    vis[u]=2;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>t;
        mainCourse.pb(t);
    }
    adj.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>t;
        for(int j=0;j<t;j++){
            cin>>x;
            adj[i].pb(x);
        }
    }
    for(int i=0;i<k;i++){
        if(!vis[mainCourse[i]]) dfs(mainCourse[i]);
    }
    cout<<Ti<<endl;
    for(int i=0;i<Ti;i++) cout<<course[i]<<" ";
    return 0;
}
