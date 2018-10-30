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
int level[2005]={0},n,Ti=0,p;
vector<vi> adj;
void dfs(int x,int l){
    level[x]=l;
    for(int i:adj[x]){
        dfs(i,l+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    adj.resize(n+1);
    up(i,1,n){
        cin>>p;
        if(p==-1) adj[0].pb(i);
        else adj[p].pb(i);
    }
    dfs(0,0);
    up(i,1,n) Ti=max(Ti,level[i]);
    cout<<Ti<<endl;
    return 0;
}
