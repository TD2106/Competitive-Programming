#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define mp make_pair
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
int Ti=2e9,n,m,items[105],item=0,a,b,d,vis[105]={0},mxItems[105]={0};
vector< vector<pii> > adj;
class Compare
{
public:
    bool operator() (piii a, piii b)
    {
        return !(a.F<b.F||(a.F==b.F&&a.S.F>b.S.F));
    }
};
void dijkstra(){
    priority_queue<piii,vector<piii>,Compare > pq;
    pq.push(mp(0,mp(items[1],1)));
    while(!pq.empty()){
        piii temp = pq.top();
        pq.pop();
        if(temp.S.S!=n&&temp.F<=vis[temp.S.S]){
            if(vis[temp.S.S]==temp.F&&temp.S.F<=mxItems[temp.S.S]) continue;
            else if(vis[temp.S.S]==temp.F&&temp.S.F>mxItems[temp.S.S]) mxItems[temp.S.S]=temp.S.F;
            else if(vis[temp.S.S]>temp.F){
                vis[temp.S.S]=temp.F;
                mxItems[temp.S.S]=temp.S.F;
            }
            for(int i=0;i<adj[temp.S.S].size();i++){
                pq.push(mp(adj[temp.S.S][i].F+temp.F,mp(temp.S.F+items[adj[temp.S.S][i].S],adj[temp.S.S][i].S)));
            }
        }
        else if(temp.S.S==n&&temp.F<=Ti){
            if(temp.F==Ti) item=max(item,temp.S.F);
            else if(temp.F<Ti) item=temp.S.F;
            Ti=min(Ti,temp.F);
        }
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	//fr("gen_031.in");
	cin>>n;
	adj.resize(n+1);
	for(int i=1;i<=n;i++) cin>>items[i],vis[i]=2e9;
	cin>>m;
	while(m--){
        cin>>a>>b>>d;
        adj[a].pb(mp(d,b));
        adj[b].pb(mp(d,a));
	}
	dijkstra();
	if(Ti!=2e9) cout<<Ti<<" "<<item<<endl;
	else cout<<"impossible\n";
	return 0;
}
