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
typedef vector<int> vi;
int trie[100005][26]={0},n,Ti[100005]={0},cnt[100005]={0},q,u,node,tc;
vector<vi> adj;
void add(const string& s){
    int v=0,temp;
    for(auto c:s){
        temp=c-'a';
        if(trie[v][temp]==0){
            trie[v][temp]=++node;
            adj[v].pb(trie[v][temp]);
        }
        v=trie[v][temp];
        cnt[v]++;
    }
}
void dfs(int x,int length){
    Ti[length]=max(Ti[length],cnt[x]);
    for(int i:adj[x]){
        dfs(i,length+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>tc;
    while(tc--){
        reset(trie);
        reset(Ti);
        reset(cnt);
        adj.clear();
        adj.resize(100005);
        node=0;
        string s;
        cin>>n>>q;
        up(i,1,n){
            cin>>s;
            reverse(all(s));
            add(s);
        }
        dfs(0,0);
        while(q--){
            cin>>u;
            cout<<Ti[u]<<endl;
        }
    }
    return 0;
}
