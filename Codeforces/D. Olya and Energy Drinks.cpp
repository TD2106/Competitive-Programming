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
int n,m,k,dis[1005][1005],xa,ya,xb,yb,Ti;
char table[1005][1005]={0};
void bfs(){
    up(i,1,n){
        up(j,1,m) dis[i][j]=2e9;
    }
    dis[xa][ya]=0;
    queue<pii> q;
    q.push({xa,ya});
    while(!q.empty()){
        int xx=q.front().fi,yy=q.front().se;
        q.pop();
        up(i,1,k){
            if(table[xx+i][yy]!='.'||dis[xx+i][yy]<=dis[xx][yy]) break;
            else if(dis[xx+i][yy]>dis[xx][yy]+1){
                dis[xx+i][yy]=dis[xx][yy]+1;
                q.push({xx+i,yy});
            }
        }
        up(i,1,k){
            if(table[xx-i][yy]!='.'||dis[xx-i][yy]<=dis[xx][yy]) break;
            else if(dis[xx-i][yy]>dis[xx][yy]+1){
                dis[xx-i][yy]=dis[xx][yy]+1;
                q.push({xx-i,yy});
            }
        }
        up(i,1,k){
            if(table[xx][yy+i]!='.'||dis[xx][yy+i]<=dis[xx][yy]) break;
            else if(dis[xx][yy+i]>dis[xx][yy]+1){
                dis[xx][yy+i]=dis[xx][yy]+1;
                q.push({xx,yy+i});
            }
        }
        up(i,1,k){
            if(table[xx][yy-i]!='.'||dis[xx][yy-i]<=dis[xx][yy]) break;
            else if(dis[xx][yy-i]>dis[xx][yy]+1){
                dis[xx][yy-i]=dis[xx][yy]+1;
                q.push({xx,yy-i});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    up(i,1,n) up(j,1,m) cin>>table[i][j];
    cin>>xa>>ya>>xb>>yb;
    bfs();
    Ti=dis[xb][yb];
    if(Ti==2e9) Ti=-1;
    cout<<Ti<<endl;
    return 0;
}
