#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int main (){
	vector<pll> times;
	pll temp;
	ll n,ans=0,cur=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp.first;
		temp.second=2;
		times.push_back(temp);
		cin>>temp.first;
		temp.second=1;
		times.push_back(temp);
	}
	sort(times.begin(),times.end());
	for(int i=0;i<times.size();i++){
		if(times[i].second==1) cur++;
		else{
			if(cur>0) cur--;
			else ans++;
		}
	}
	cout<<ans<<endl;
}
