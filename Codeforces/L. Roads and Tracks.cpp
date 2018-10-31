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
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pll,pii> pllii;
int n,m,tc;
ll a[25030][30],b[25030][30];
bool vis[25030][30];
void dijkstra(){
    priority_queue<pllii,vector<pllii>,greater<pllii> > pq;
    pq.push({{0LL,0LL},{1,1}});
    pllii Ti;
    while(!pq.empty()){
        Ti=pq.top();
        pq.pop();
        int i=Ti.se.fi,j=Ti.se.se;
        if(i==n+1){
            cout<<Ti.fi.fi<<" "<<Ti.fi.se<<endl;
            return;
        }
        if(vis[i][j]) continue;
        vis[i][j]=1;
        if(j!=1&&j!=m){
            pq.push({{Ti.fi.fi,Ti.fi.se+b[i][j]},{i,j+1}});
            pq.push({{Ti.fi.fi,Ti.fi.se+b[i][j-1]},{i,j-1}});
            pq.push({{Ti.fi.fi+a[i][j],Ti.fi.se},{i+1,j}});
        }
        else if(j==1){
            pq.push({{Ti.fi.fi,Ti.fi.se+b[i][j]},{i,j+1}});
            pq.push({{Ti.fi.fi+a[i][j],Ti.fi.se},{i+1,j}});
        }
        else{
            pq.push({{Ti.fi.fi,Ti.fi.se+b[i][j-1]},{i,j-1}});
            pq.push({{Ti.fi.fi+a[i][j],Ti.fi.se},{i+1,j}});
        }
    }
}
int main(){
	ios_base::sync_with_stdio(0);
    cin>>tc;
    while(tc--){
        reset(vis);
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m-1;j++){
                cin>>b[i][j];
            }
        }
        dijkstra();
    }
	return 0;
}
