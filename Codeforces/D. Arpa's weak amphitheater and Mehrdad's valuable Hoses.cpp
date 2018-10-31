#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
int n,m,w,b[1001]={0},we[1001]={0},d[1001],u,v,dp[1001][1001]={0},sumw,sumb,Ti;
vector<vector<pii>> fr,te;
int fn(int x){
    if(x==d[x]) return x;
    else return d[x]=fn(d[x]);
}
void un(int u,int v){
    u=fn(u);
    v=fn(v);
    d[u]=v;
}
int main(){
    cin>>n>>m>>w;
    for(int i=1;i<=n;i++) cin>>we[i];
    for(int i=1;i<=n;i++) cin>>b[i],d[i]=i;
   // cout<<fn(1)<<" "<<fn(2)<<endl;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        un(u,v);
    }
    //for(int i=1;i<=n;i++) cout<<d[i]<<" ";
    fr.resize(n+1);
    for(int i=1;i<=n;i++) fr[fn(i)].pb(mp(b[i],we[i]));
    for(int i=1;i<=n;i++) if(fr[i].size()) te.pb(fr[i]);
    fr.clear();
    fr=te;
    te.clear();
   // cout<<fr.size()<<endl;
    for(int i=0;i<fr.size();i++){
        if(fr[i].size()==1) continue;
        sumw=sumb=0;
        for(int j=0;j<fr[i].size();j++){
            sumb+=fr[i][j].F;
            sumw+=fr[i][j].S;
        }
        fr[i].pb(mp(sumb,sumw));
    }
    /*for(int i=0;i<fr.size();i++){
        for(int j=0;j<fr[i].size();j++) cout<<fr[i][j].F<<" "<<fr[i][j].S<<" ";
        cout<<endl;
    }*/
    for(int i=1;i<=fr.size();i++){
        for(int j=1;j<=w;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            for(int k=0;k<fr[i-1].size();k++){
                if(fr[i-1][k].S<=j) dp[i][j]=max(dp[i][j],dp[i-1][j-fr[i-1][k].S]+fr[i-1][k].F);
            }
        }
    }
    Ti=dp[fr.size()][w];
    cout<<Ti<<endl;
    return 0;
}
