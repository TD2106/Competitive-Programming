#include <iostream>
using namespace std;
typedef long long ll;
ll n,m,lo,hi,q[100010]={0};
bool check (ll t){
	int j=1,i=1;
	ll temp=t;
	while(i<=n&&j<=m){
		temp=t;
		while(q[i]<=temp&&i<=n){
			temp-=q[i];
			i++;
		}
		j++;
	}
	if(i==n+1&&j<=m+1)
	return true;
	else return false;
}
int main (){
	lo=1,hi=1000000000000000000;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
		lo=max(lo,q[i]);
	}
	while(lo<hi){
		ll mid=(lo+hi)/2;
		if(check(mid)){
			hi=mid;
		}
		else{
			lo=mid;
		}
	}
	cout<<(lo+hi)/2;
	return 0;
}
