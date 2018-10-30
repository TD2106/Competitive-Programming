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
typedef pair<int,pii> piii;
char table[1505][1505]={0};
int Ti,n,m,meltDay[1505][1505]={0},dr[4]={1,-1,0,0},dc[4]={0,0,-1,1},cnt=0;
queue<pii> q,q2;
bool vis[1505][1505]={0},inQueue[1505][1505]={0};
pii swan[2];
bool isValid(int x,int y){
    return (x>=1&&y>=1&&x<=n&&y<=m);
}
void bfs1(){
    reset(vis);
    while(!q.empty()){
        pii temp = q.front();
        q.pop();
        if(vis[temp.fi][temp.se]) continue;
        vis[temp.fi][temp.se]=1;
        up(i,0,3){
            int x=temp.fi+dr[i];
            int y=temp.se+dc[i];
            if(table[x][y]=='X'){
                if(meltDay[x][y]>meltDay[temp.fi][temp.se]+1){
                    meltDay[x][y]=meltDay[temp.fi][temp.se]+1;
                    q.push({x,y});
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    up(i,1,n){
        up(j,1,m){
            cin>>table[i][j];
            meltDay[i][j]=1e9;
            if(table[i][j]!='X'){
                 q.push({i,j});
                 meltDay[i][j]=0;
            }
            if(table[i][j]=='L'){
                swan[cnt].fi=i;
                swan[cnt].se=j;
                cnt++;
            }
        }
    }
    bfs1();
    q.push(swan[0]);
    reset(vis);
    inQueue[swan[0].fi][swan[0].se]=1;
    for(Ti=0;!q.empty()||!q2.empty();Ti++){
        int t=q2.size();
        up(i,1,t){
            pii temp = q2.front();
            q2.pop();
            if(meltDay[temp.fi][temp.se]<=Ti) q.push(temp);
            else q2.push(temp);
        }
        while(!q.empty()){
            pii temp = q.front();
            q.pop();
            if(temp.fi==swan[1].fi&&temp.se==swan[1].se){
                cout<<Ti<<endl;
                return 0;
            }
            if(vis[temp.fi][temp.se]) continue;
            vis[temp.fi][temp.se]=1;
            up(i,0,3){
                int x=temp.fi+dr[i];
                int y=temp.se+dc[i];
                if(!isValid(x,y)||inQueue[x][y]) continue;
                inQueue[x][y]=1;
                if(meltDay[x][y]<=Ti) q.push({x,y});
                else q2.push({x,y});
            }
        }
    }
    return 0;
}
