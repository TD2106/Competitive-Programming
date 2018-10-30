#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define mp make_pair
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long int ll;
typedef pair<string,string> pss;
vector<pss> city;
int n;
ll Ti=0;
string s1,s2;
int main(){
	ios_base::sync_with_stdio(0);
	fr("SCITY.INP");
	fw("SCITY.OUT");
	cin>>n;
	for(int i=0;i<n;i++){
        cin>>s1>>s2;
        city.pb(mp(s1.substr(0,2),s2));
	}
	sort(city.begin(),city.end());
	for(int i=0;i<n;i++){
        if(city[i].F==city[i].S) continue;
        else{
            pss temp=mp(city[i].S,city[i].F);
            Ti+=(ll)(upper_bound(city.begin(),city.end(),temp)-lower_bound(city.begin(),city.end(),temp));
        }
	}
	Ti/=2;
	cout<<Ti<<endl;
	return 0;
}
