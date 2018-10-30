#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
int cal(pii a){
	return (a.second-a.first-1);
}
bool cmp(pii a,pii b){
	return ((a.second-a.first)<(b.second-b.first));
}
int main (){
	int n,k,t,ans=1;
	vi day;
	vpii seg;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>t;
		if(t<0) day.push_back(i);
	}
	if((int)day.size()>k){
		cout<<-1<<endl;
		return 0;
	}
	if(day.size()==0){
		cout<<0<<endl;
		return 0;
	}
	if(k==n){
		cout<<1<<endl;
		return 0;
	}
	for(int i=0;i<day.size()-1;i++){
		if(day[i]!=day[i+1]-1) ans+=2;
	}
	if(day[day.size()-1]!=n) ans++;
	k-=day.size();
	if(k==0){
		cout<<ans<<endl;
		return 0;
	}
	for(int i=0;i<day.size()-1;i++) 
	if(day[i]!=day[i+1]-1) seg.push_back(make_pair(day[i],day[i+1]));
	sort(seg.begin(),seg.end(),cmp);
	for(int i=0;i<seg.size();i++){
		if(k>=cal(seg[i])) ans-=2,k-=cal(seg[i]);
	}
	if(day[day.size()-1]!=n&&k>=(n-day[day.size()-1])) ans--;
	cout<<ans<<endl;
	return 0;
}
