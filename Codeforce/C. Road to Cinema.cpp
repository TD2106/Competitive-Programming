#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#define F first
#define S second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
vpii cars;
vpii::iterator itr1;
vi::iterator itr2;
int n,k,s,t,l=1,u=1000000000,g[200010]={0},mid,c,v;
int caltime(int a,int b,int v){
	if(b-a>v) return -1;
	else return max(b-a,3*(b-a)-v);
}
bool check(int dis){
	int ti=0;
	for(int i=0;i<=k;i++){
		if(caltime(g[i],g[i+1],dis)==-1) return 0;
		else ti+=caltime(g[i],g[i+1],dis);
	}
	return (ti<=t);
}
int main (){
	cin>>n>>k>>s>>t;
	for(int i=0;i<n;i++){
		cin>>c>>v;
		cars.push_back(make_pair(c,v));
	}
	for(int i=1;i<=k;i++) cin>>g[i];
	cars.push_back(make_pair(0,0));
	sort(cars.begin(),cars.end());
	sort(g+1,g+k+1);
	g[k+1]=s;
	for(int i=1;i<=n;i++) cars[i].S=max(cars[i].S,cars[i-1].S);
	if(!check(cars[cars.size()-1].S)){
		cout<<-1<<endl;
		return 0;
	}
	while(l<u){
		mid=(l+u)/2;
		itr1=upper_bound(cars.begin(),cars.end(),make_pair(mid,1000000000));
		itr1--;
		//cout<<mid<<" "<<0<<endl;
		//cout<<itr1->F<<" "<<itr1->S<<endl;
		if(check(itr1->S)) u=mid;
		else l=mid+1;
		//cout<<l<<" "<<u<<endl;
	}
	//cout<<check(8)<<endl;
	cout<<(l+u)/2<<endl;
	return 0;
}
