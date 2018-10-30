#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
bool isInstall[10005]={0};
ll n,m,s,l,u,v,d,Ti,cnt,temp;
plll t;
pll t2;
vector< vector<pll> > tree;
int tc,dsu[10005];
int findDSU(int x){
    if(x==dsu[x]) return x;
    else return dsu[x]=findDSU(dsu[x]);
}
void unionDSU(int x,int y){
    x=findDSU(x);
    y=findDSU(y);
    dsu[x]=y;
}
priority_queue< plll,vector<plll>,greater<plll> > pq;
priority_queue< pll,vector<pll>,greater<pll> > pq2;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>tc;
	while(tc--){
        reset(isInstall);
        Ti=cnt=0;
        cin>>n>>m>>l>>s;
        for(int i=1;i<=n;i++) dsu[i]=i;
        tree.clear();
        tree.resize(n+1);
        for(int i=1;i<=s;i++){
            cin>>temp;
            isInstall[temp]=1;
        }
        for(int i=1;i<=m;i++){
            cin>>u>>v>>d;
            pq.push(mp(d,mp(u,v)));
        }
        while(cnt!=n-1&&!pq.empty()){
            t=pq.top();
            pq.pop();
            if(findDSU(t.S.F)==findDSU(t.S.S)) continue;
            cnt++;
            tree[t.S.F].pb(mp(t.S.S,t.F));
            tree[t.S.S].pb(mp(t.S.F,t.F));
            unionDSU(t.S.F,t.S.S);
        }
        while(!pq.empty()) pq.pop();
        for(int i=1;i<=n;i++){
            if(isInstall[i]){
                for(int j=0;j<tree[i].size();j++){
                    pq2.push(mp(tree[i][j].S,tree[i][j].F));
                }
            }
        }
        cnt=0;
        while(!pq2.empty()){
            t2=pq2.top();
            pq2.pop();
            if(isInstall[t2.S]) continue;
            isInstall[t2.S]=1;
            Ti+=t2.F;
            //cout<<t2.S<<" ";
            for(int i=0;i<tree[t2.S].size();i++){
                pq2.push(mp(tree[t2.S][i].S,tree[t2.S][i].F));
            }
        }
        //cout<<endl;
        //cout<<cnt<<" "<<n-s<<endl;
        Ti+=(n-s)*l;
        cout<<Ti<<endl;
	}
	return 0;
}
