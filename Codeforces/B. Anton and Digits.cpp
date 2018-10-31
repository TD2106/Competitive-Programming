#include <iostream>
using namespace std;
typedef long long ll;
int main (){
	ll k1,k2,k3,k4,sum=0;
	cin>>k1>>k2>>k3>>k4;
	sum+=256*min(min(k1,k3),k4);
	k1-=min(min(k1,k3),k4);
	sum+=32*min(k1,k2);
	cout<<sum<<endl;
}
