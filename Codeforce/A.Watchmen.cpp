#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll n,x[200010]={0},y[200010]={0},ans=0,countx=1,county=1,countp=1;
pll pos[200010];
int main(){
	cin>>n;
	pos[0].first=pos[0].second=x[0]=y[0]=2000000000;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		pos[i].first=x[i];
		pos[i].second=y[i];
	}
	sort(x+1,x+n+1);
	sort(y+1,y+n+1);
	sort(pos+1,pos+n+1);
	/*for(int i=1;i<=n;i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<y[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<pos[i].first<<" "<<pos[i].second<<" ";
	}
	cout<<endl;*/
	for(int i=1;i<=n;i++){
		//cout<<i<<endl;
		if(x[i]==x[i-1]) countx++;
		else{
		//	cout<<"x "<<countx<<endl;
			ans+=countx*(countx-1)/2;
			countx=1;
		}
		if(y[i]==y[i-1]) county++;
		else{
		//	cout<<"y "<<county<<endl;
			ans+=county*(county-1)/2;
			county=1;
		}
		if(pos[i]==pos[i-1]) countp++;
		else{
		//	cout<<"p "<<countp<<endl;
			ans-=countp*(countp-1)/2;
			countp=1;
		}
	}
	ans+=countx*(countx-1)/2+county*(county-1)/2-countp*(countp-1)/2;
	cout<<ans<<endl;
}
