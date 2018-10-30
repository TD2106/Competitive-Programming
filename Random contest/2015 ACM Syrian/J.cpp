#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
#define fr(a) freopen(a,"r",stdin);
#define fw(a) freopen(a,"w",stdout);
#define tc() int tc;cin >> tc; for(int _tc=1;_tc<=tc;_tc++)
#define up(i,l,r) for (int i=l;i<=r;i++)
#define down(i,r,l) for (int i=r;i>=l;i--)
#define rep(i,l,r) for (int i=l;i<r;i++)
#define pb push_back
#define mp make_pair
#define ins insert
#define fi first
#define se second
#define reset(x) memset(x,0,sizeof(x))
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<string,int> psi;
/****************************************************/
void printArr(int a[], int l, int r)
{ up(i,l,r) cout << a[i] << " \n"[i==r]; }

void printMtx(int a[][1010],int n, int m)
{ up(i,1,n) up(j,1,m) cout << a[i][j] << " \n"[j==m]; }
/****************************************************/
map<string,int> key;
vector< vector<psi> > adj;
vector<psi> ans;
bool vis[100005]={0};
int n,k,c;
string s,s1;

void dfs(psi x){
    vis[x.se]=1;
    for(auto temp:adj[x.se]){
        if(!vis[temp.se]){
            dfs(temp);
        }
    }
    ans.pb(x);
}
bool cmp(const psi& a,const psi& b){
    return (a.se<b.se);
}
int main()
{
    ios_base::sync_with_stdio(0);
    tc(){
        key.clear();
        adj.clear();
        ans.clear();
        reset(vis);
        cin>>n>>k;
        adj.resize(n+1);
        up(i,1,n){
            cin>>s>>c;
            key[s]=i;
            up(j,1,c){
                cin>>s1;
                adj[i].pb({s1,key[s1]});
            }
        }

        up(i,1,k){
            cin>>s;
            if(!vis[key[s]]){
                dfs({s,key[s]});
            }
        }
        sort(all(ans),cmp);
        for(auto temp:ans) cout<<temp.fi<<endl;
    }
}
