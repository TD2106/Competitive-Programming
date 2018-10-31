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
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
int n,k,Timoney=0,temp;
vector<pii> Titable;
piii reserve[1005];
multiset<pii> table;
bool cmp(piii a,piii b){
    return ((a.fi.fi>b.fi.fi)||(a.fi.fi==b.fi.fi&&a.fi.se<b.fi.se));
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	up(i,1,n) cin>>reserve[i].fi.se>>reserve[i].fi.fi,reserve[i].se=i;
	cin>>k;
	up(i,1,k){
        cin>>temp;
        table.insert({temp,i});
	}
	sort(reserve+1,reserve+1+n,cmp);
	up(i,1,n){
        if(table.empty()) break;
        multiset<pii>::iterator itr = table.lower_bound({reserve[i].fi.se,0});
        if(itr!=table.end()) {Timoney+=reserve[i].fi.fi;
        Titable.pb({reserve[i].se,itr->se});
        table.erase(*itr);}
	}
	cout<<k-table.size()<<" "<<Timoney<<endl;
	for(auto t:Titable) cout<<t.fi<<" "<<t.se<<endl;
	return 0;
}
