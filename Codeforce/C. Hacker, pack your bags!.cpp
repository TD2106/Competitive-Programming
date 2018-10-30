#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define F first
#define S second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
int Ti=2e9+1,n,x,r,l,temp=0,c,t;
map< int,vector< pair<pii,int> > > data;
map< int,vector< pair<pii,int> > >::iterator itr;
vector< pair<pii,int> >::iterator binarySearchItr;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>x;
	for(int i=1;i<=n;i++){
        cin>>l>>r>>c;
        data[r-l+1].pb(mp(mp(l,c),0));
	}
	for(itr=data.begin();itr!=data.end();itr++){
        sort((itr->S).begin(),(itr->S).end());
        for(int i=(itr->S).size()-1;i>=0;i--){
            if(i==(itr->S).size()-1) (itr->S)[i].S=(itr->S)[i].F.S;
            else (itr->S)[i].S=min((itr->S)[i+1].S,(itr->S)[i].F.S);
        }
	}
	for(itr=data.begin();itr!=data.end();itr++){
        t=x-itr->F;
        if(data.count(t)==0) continue;
        for(int i=0;i<(itr->S).size();i++){
            temp=(itr->S)[i].F.S;
            binarySearchItr=lower_bound(data[t].begin(),data[t].end(),mp(mp((itr->S)[i].F.F+(itr->F),0),0));
            if(binarySearchItr==data[t].end()) continue;
            temp+=binarySearchItr->S;
            Ti=min(Ti,temp);
        }
	}
	if(Ti!=2e9+1) cout<<Ti<<endl;
	else cout<<-1<<endl;
	return 0;
}
