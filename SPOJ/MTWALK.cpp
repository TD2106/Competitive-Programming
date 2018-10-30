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
typedef pair<int, pair<pii,pii> > piiiii;
int m,n,moutain[505][505],dp[505][505],Ti=0,dr[]={1,-1,0,0},dc[]={0,0,1,-1};
bool vis[505][505]={0};
void dijkstra(){
    priority_queue< piiiii,vector<piiiii>,greater<piiiii> > pq;
    pq.push({0,{{1,1},{moutain[1][1],moutain[1][1]}}});
    piiiii temp;
    while(!pq.empty()){
        temp = pq.top();
        int r=temp.S.F.F,c=temp.S.F.S,d=temp.F,mx=temp.S.S.F,mn=temp.S.S.S,t;
        pq.pop();
        if(vis[r][c]) continue;
//        bug(r);
//        bug(c);
//        bug(d);
//        bug(mn);
//        bug(mx);
        vis[r][c]=1;
        up(i,0,3){
            int rr=r+dr[i],cc=c+dc[i];
//            bug(rr);
//            bug(cc);
            if(moutain[rr][cc]!=-1){
                t=moutain[rr][cc];
                if(t<mn) dp[rr][cc]=min(dp[rr][cc],max(d,abs(mx-t)));
                else if(t>mx) dp[rr][cc]=min(dp[rr][cc],max(d,abs(t-mn)));
                else dp[rr][cc]=min(dp[rr][cc],d);
                if(!vis[rr][cc]) pq.push({dp[rr][cc],{{rr,cc},{max(mx,t),min(mn,t)}}});
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
