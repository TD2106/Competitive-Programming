#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll l=1,u=1000000000000000000000LL,cnt1,cnt2,x,y,mid;
bool check (ll a){
	if((a-a/x)>=cnt1&&(a-a/y)>=cnt2) return 1;
	return 0;
}
int main (){
	cin>>cnt1>>cnt2>>x>>y;
	while(l<u){
		mid=(l+u)/2;
		//cout<<mid<<" "<<check(mid)<<endl;
		if(check(mid)) u=mid;
		else l=mid+1;
	}
	//cout<<u<<" "<<l<<endl;
	cout<<(l+u)/2<<endl;
	return 0;
}
