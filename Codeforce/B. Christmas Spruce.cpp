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
int n,p,cnt;
vector<vi> adj;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    adj.resize(n+1);
    up(i,2,n){
        cin>>p;
        adj[p].pb(i);
    }
    up(i,1,n){
        if(adj[i].size()){
            cnt=0;
            for(int t:adj[i]){
                if(!adj[t].size()) cnt++;
            }
            if(cnt<3){
                cout<<"No\n";
                return 0;
            }
        }
    }
    cout<<"Yes\n";
    return 0;
}
