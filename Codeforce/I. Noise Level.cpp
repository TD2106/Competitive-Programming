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
ll n,m,p,q,total[255][255]={0},Ti=0;
int dr[]={0,0,-1,1},dc[]={1,-1,0,0};
vector< pair<ll,pii> > sources;
bool vis[255][255]={0};
char table[255][255]={0};
void bfs(const pair<ll,pii>& a){
    reset(vis);
    queue< pair<ll,pii> > q;
    q.push(a);
    while(!q.empty()){
        pair<ll,pii> temp = q.front();
        q.pop();
        if(vis[temp.se.fi][temp.se.se]||temp.fi==0) continue;
        vis[temp.se.fi][temp.se.se]=1;
        total[temp.se.fi][temp.se.se]+=temp.fi;
        up(i,0,3){
            int r=temp.se.fi+dr[i],c=temp.se.se+dc[i];
            if(table[r][c]=='.'||(table[r][c]>='A'&&table[r][c]<='Z')){
                q.push({temp.fi/2,{r,c}});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>q>>p;
    up(i,1,n){
        up(j,1,m){
            cin>>table[i][j];
            if(table[i][j]>='A'&&table[i][j]<='Z'){
                ll t=table[i][j]-'A'+1;
                t*=q;
                sources.pb({t,{i,j}});
            }
        }
    }
    for(auto t:sources){
        bfs(t);
    }
    up(i,1,n){
        up(j,1,m) if(total[i][j]>p) Ti++;
    }
    cout<<Ti<<endl;
    return 0;
}
