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
vector< vector<pii> > walk,car,walkRev,carRev;
int n,m,k,Ti=1e9,u,v,c1,c2,fromOneWalk[10005],fromOneCar[10005],toKWalk[10005],toNCar[10005];
bool vis[10005];
void dijsktra(int x,int a[],const vector< vector<pii> > &v){
    reset(vis);
    up(i,1,n) a[i]=1e9;
    a[x]=0;
    priority_queue< pii,vector<pii>,greater<pii> > pq;
    pq.push(mp(0,x));
    while(!pq.empty()){
        pii temp=pq.top();
        pq.pop();
        if(vis[temp.se]) continue;
        a[temp.se]=min(temp.fi,a[temp.se]);
        vis[temp.se]=1;
        for(int i=0;i<v[temp.se].size();i++){
            if(!vis[v[temp.se][i].fi]){
                pq.push(mp(temp.fi+v[temp.se][i].se,v[temp.se][i].fi));
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    walk.resize(n+1);
    car.resize(n+1);
    walkRev.resize(n+1);
    carRev.resize(n+1);
    up(i,1,m){
        cin>>u>>v>>c1>>c2;
        walk[u].pb(mp(v,c1));
        walkRev[v].pb(mp(u,c1));
        car[u].pb(mp(v,c2));
        carRev[v].pb(mp(u,c2));
    }
    dijsktra(1,fromOneCar,car);
    dijsktra(1,fromOneWalk,walk);
    dijsktra(k,toKWalk,walkRev);
    dijsktra(n,toNCar,carRev);
    up(i,1,n){
        if(fromOneCar[i]+toKWalk[i]<60){
            Ti=min(Ti,fromOneCar[i]+toNCar[i]);
        }
    }
    cout<<Ti<<endl;
    return 0;
}
