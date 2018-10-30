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
int n,k,Ti=0,component[1005][1005]={0},componentSize[250005]={0},g=0,dr[4]={1,-1,0,0},dc[4]={0,0,-1,1};
char table[1005][1005]={0};
bool vis[250005]={0};
vi v;
void dfs(int r,int c,int group){
    component[r][c]=group;
    componentSize[g]++;
    up(i,0,3){
        int rr=r+dr[i],cc=c+dc[i];
        if(component[rr][cc]==0&&table[rr][cc]=='.'){
            dfs(rr,cc,group);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    vis[0]=1;
    up(i,1,n){
        up(j,1,n) cin>>table[i][j];
    }
    up(i,1,n){
        up(j,1,n){
            if(component[i][j]==0&&table[i][j]=='.'){
                dfs(i,j,++g);
            }
        }
    }
    up(i,1,n){
        if(i+k-1<=n){
            up(l,i,i+k-1){
                up(m,1,k){
                    if(table[l][m]=='.'){
                        componentSize[component[l][m]]--;
                    }
                }
            }
        }
        up(j,1,n){
            if(i+k-1<=n&&j+k-1<=n){
                int temp=k*k;
                up(l,i,i+k-1){
                    up(c,0,3){
                        int t1=l+dr[c],t2=j+dc[c];
                        if(vis[component[t1][t2]]==0){
                            v.pb(component[t1][t2]);
                            vis[component[t1][t2]]=1;
                        }
                        t2=j+k-1+dc[c];
                        if(vis[component[t1][t2]]==0){
                            v.pb(component[t1][t2]);
                            vis[component[t1][t2]]=1;
                        }
                    }
                }
                up(l,j,j+k-1){
                    up(c,0,3){
                        int t1=i+dr[c],t2=l+dc[c];
                        if(vis[component[t1][t2]]==0){
                            v.pb(component[t1][t2]);
                            vis[component[t1][t2]]=1;
                        }
                        t1=i+k-1+dr[c];
                        if(vis[component[t1][t2]]==0){
                            v.pb(component[t1][t2]);
                            vis[component[t1][t2]]=1;
                        }
                    }
                }
                for(int t:v){
                    temp+=componentSize[t];
                    vis[t]=0;
                }
                v.clear();
//                bug(i);
//                bug(j);
//                bug(temp);
                Ti=max(Ti,temp);
            }
            if(i+k-1<=n){
                up(l,i,i+k-1){
                    if(table[l][j]=='.') componentSize[component[l][j]]++;
                    if(table[l][j+k]=='.') componentSize[component[l][j+k]]--;
                }
            }
        }
    }
    cout<<Ti<<endl;
    return 0;
}
