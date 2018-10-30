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
int Ti=0,n,m,vis[105][105]={0},dr[]={1,-1,0,0},dc[]={0,0,-1,1};
pii src,des;
char table[105][105]={0};
queue<piii> q;
void bfs(){
    q.push({1,src});
    up(i,1,n){
        up(j,1,m) vis[i][j]=-1;
    }
    while(!q.empty()){
        piii temp = q.front();
        q.pop();
        int x=temp.se.fi,y=temp.se.se;
        if(vis[x][y]>=temp.fi) continue;
        vis[x][y]=temp.fi;
        up(i,0,3){
            int xx=x+dr[i],yy=y+dc[i];
            if(vis[xx][yy]<=temp.fi&&table[xx][yy]=='.'||table[xx][yy]=='B'){
                if(table[xx][yy]=='.'){
                    q.push({temp.fi+1,{xx,yy}});
                }
                else if(table[xx][yy]=='*'){
                    q.push({temp.fi,{xx,yy}});
                }
                else if(table[xx][yy]=='B'){
                    Ti=temp.fi;
                    return;
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
            if(table[i][j]=='B') des.fi=i,des.se=j;
            if(table[i][j]=='C') src.fi=i,src.se=j;
        }
    }
    bfs();
    cout<<Ti<<endl;
    return 0;
}
