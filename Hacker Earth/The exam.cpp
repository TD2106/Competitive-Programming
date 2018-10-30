#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main (){
	ll tc,x,l,n,t1;
	cin>>tc;
	while(tc--){
		cin>>x>>l>>n;
		if(n==0){
			cout<<0<<endl;
			continue;
		}
		t1=l;
		while(n&&t1){
			t1=(ll)ceil(t1*1.0/2);
			n--;
		}
		if(n==0){
			cout<<max(0LL,x-t1)<<endl;
		}
		else{
			cout<<l<<endl;
		}
	}
	return 0;
}
