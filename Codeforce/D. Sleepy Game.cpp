#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool state[100005][2]={0},hasCycle=0;
int n,k,v,result=0,vis[100005]={0},m,s;
vector<vi> adj,rev;
vi Ti;
void dfs(int x){
    vis[x]=1;
    if(hasCycle) return;
    for(int i:adj[x]){
        if(vis[i]==0) dfs(i);
        else if(vis[i]==1){
            hasCycle=1;
            return;
        }
    }
    vis[x]=2;
}
void dfs2(int x,int st){
    state[x][st]=1;
    Ti.pb(x);
    if(st==1&&adj[x].size()==0){
        result=2;
        return;
    }
    if(result==2) return;
    for(int i:adj[x]){
        if(state[i][(st+1)%2]==0) dfs2(i,(st+1)%2);
        if(result==2) return;
    }
    Ti.pop_back();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    adj.resize(n+1);
    rev.resize(n+1);
    up(i,1,n){
        cin>>k;
        up(j,1,k){
            cin>>v;
            adj[i].pb(v);
            rev[v].pb(i);
        }
    }
    cin>>s;
    dfs(s);
    if(hasCycle) result=1;
    dfs2(s,0);
    up(i,1,n){
        if(adj[i].size()==0&&state[i][1]){
            result=2;
            break;
        }
    }
    if(result==0) cout<<"Lose";
    else if(result==1) cout<<"Draw";
    else{
        cout<<"Win\n";
        for(int i:Ti) cout<<i<<' ';
    }
    return 0;
}
