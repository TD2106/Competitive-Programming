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
int n,m,u,v,Ti=0,outDegree[300005]={0},dp[300005][26]={0};
vector<vi> rev;
set<pii> existed;
vi topoSorted;
queue<int> q;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    cin>>s;
    s="#"+s;
    rev.resize(n+1);
    up(i,1,m){
        cin>>u>>v;
        if(!existed.count({u,v})){
            existed.insert({u,v});
            outDegree[u]++;
            rev[v].pb(u);
        }
        if(u==v){
            cout<<-1<<endl;
            return 0;
        }
    }
    up(i,1,n){
        if(outDegree[i]==0) q.push(i);
    }
    while(!q.empty()){
        u=q.front();
        q.pop();
        topoSorted.pb(u);
        for(int i:rev[u]){
            outDegree[i]--;
            if(outDegree[i]==0) q.push(i);
        }
    }
    if(topoSorted.size()!=n){
        cout<<-1<<endl;
        return 0;
    }
    for(int i:topoSorted){
        dp[i][s[i]-'a']++;
        for(int j:rev[i]){
            up(k,0,25){
                dp[j][k]=max(dp[j][k],dp[i][k]);
            }
        }
        up(j,0,25) Ti=max(Ti,dp[i][j]);
    }
    cout<<Ti<<endl;
    return 0;
}
