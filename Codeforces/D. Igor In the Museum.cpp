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
typedef pair<pii,pii> piiii;
int n,m,k,x,y,dr[]={1,-1,0,0},dc[]={0,0,-1,1},component[1005][1005]={0},Ti[1000005]={0},cnt=0;
char table[1005][1005]={0};
bool vis[1005][1005]={0};
void dfs(int r,int c,int g){
    vis[r][c]=1;
    component[r][c]=g;
    up(i,0,3){
        int rr=r+dr[i],cc=c+dc[i];
        if(table[rr][cc]=='.'&&vis[rr][cc]==0) dfs(rr,cc,g);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    up(i,1,n){
        up(j,1,m) cin>>table[i][j];
    }
    up(i,1,n){
        up(j,1,m){
            if(table[i][j]=='.'&&vis[i][j]==0) dfs(i,j,++cnt);
        }
    }
    up(i,1,n){
        up(j,1,m){
            if(table[i][j]=='.'){
                up(k,0,3){
                    int r=i+dr[k],c=j+dc[k];
                    if(table[r][c]=='*'){
                        Ti[component[i][j]]++;
                    }
                }
            }
        }
    }
    while(k--){
        cin>>x>>y;
        cout<<Ti[component[x][y]]<<endl;
    }
    return 0;
}
