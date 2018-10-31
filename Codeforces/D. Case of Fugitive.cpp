#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define mp make_pair
using namespace std;
typedef long long int ll;
ll n,m,t;
pair<ll,ll> island[200005];
pair< pair<ll,ll>,int > dis[200005];
set < pair<ll,int> > bridge;
set< pair<ll,int> >::iterator itr;
int Ti[200005];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>island[i].first>>island[i].second;
        if(i!=1){
            dis[i-1].first.first=island[i].second-island[i-1].first;
            dis[i-1].first.second=island[i].first-island[i-1].second;
            dis[i-1].second=i-1;
        }
    }
    sort(dis+1,dis+n);
    for(int i=1;i<=m;i++){
        cin>>t;
        bridge.insert(mp(t,i));
    }
    for(int i=1;i<=n-1;i++){
        itr=bridge.lower_bound(mp(dis[i].first.second,0));
        if(itr==bridge.end()){
            cout<<"No\n";
            return 0;
        }
        if(itr->first>dis[i].first.first){
            cout<<"No\n";
            return 0;
        }
        Ti[dis[i].second]=itr->second;
        bridge.erase(itr);
    }
    cout<<"Yes\n";
    for(int i=1;i<=n-1;i++) cout<<Ti[i]<<" ";
	return 0;
}
