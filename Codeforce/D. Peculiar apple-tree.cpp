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
int level[100005]={0},Ti=0,n,p,temp,cnt[100005]={0};
vector<vi> adj;
bool vis[100005]={0};
void dfs(int x,int l){
    vis[x]=1;
    level[x]=l;
    cnt[level[x]]++;
    for(int i:adj[x]){
        if(!vis[i]){
            dfs(i,l+1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    adj.resize(n+1);
    up(i,2,n){
        cin>>p;
        adj[p].pb(i);
    }
    dfs(1,1);
    up(i,1,n) Ti+=cnt[i]%2;
    cout<<Ti<<endl;
    return 0;
}
