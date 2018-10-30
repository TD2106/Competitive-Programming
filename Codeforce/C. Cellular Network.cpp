#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
ll n,m,city[100005]={0},cel[100005]={0},ans,l=0,u=2000000000,ici,ice,mid;
bool check(int dis){
	ice=ici=0;
	while(ici<n&&ice<m){
		if(abs(city[ici]-cel[ice])<=dis) ici++;
		else ice++;
	}
	if(ici!=n)
	return 0;
	else return 1;
}
int main (){
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>city[i];
	for(int i=0;i<m;i++) cin>>cel[i];
	sort(city,city+n);
	sort(cel,cel+m);
	while(l<u){
		mid=(l+u)/2;
		if(check(mid)) u=mid;
		else l=mid+1;
	}
	cout<<(l+u)/2<<endl;
	return 0;
}
