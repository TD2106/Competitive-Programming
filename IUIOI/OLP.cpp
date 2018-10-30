#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define reset(x) memset(x,0,sizeof(x))
#define F first
#define S second
#define mp make_pair
#define up(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
int m,n,moutain[505][505],dp[505][505],Ti=0,dr[]={1,-1,0,0},dc[]={0,0,1,-1};
bool vis[505][505]={0};
void dijkstra(){
    priority_queue< piii,vector<piii>,greater<piii> > pq;
    pq.push(mp(0,mp(1,1)));
    piii temp;
    while(!pq.empty()){
        temp = pq.top();
        int r=temp.S.F,c=temp.S.S,d=temp.F;
        pq.pop();
        if(vis[r][c]) continue;
        vis[r][c]=1;
//        bug(r);
//        bug(c);
        up(i,0,3){
            int rr=r+dr[i],cc=c+dc[i];
//            bug(rr);
//            bug(cc);
            if(moutain[rr][cc]!=-1){
                dp[rr][cc]=min(dp[rr][cc],max(dp[r][c],abs(moutain[r][c]-moutain[rr][cc])));
                if(!vis[rr][cc]) pq.push(mp(dp[rr][cc],mp(rr,cc)));
            }
        }
    }
}
void init(){
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            moutain[i][j]=-1;
            dp[i][j]=2e9;
        }
    }
}
int main(){
	ios_base::sync_with_stdio(0);
//	fr("OLP.INP");
//	fw("OLP.OUT");
	cin>>n;
	init();
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>moutain[i][j];
        }
	}
	dp[1][1]=0;
	dijkstra();
	cout<<dp[n][n]<<endl;
	return 0;
}
