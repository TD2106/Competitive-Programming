#include <iostream>
using namespace std;
typedef long long ll;
int main (){
	ll m,n,a1[5]={0},a2[5]={0},ans=0;
	cin>>m>>n;
	for(int i=0;i<5;i++){
		a1[i]=m/5;
		a2[i]=n/5;
	}
	m%=5;
	n%=5;
	for(int i=0;i<5;i++){
		if(m){
			a1[i]++;
			m--;
		}
		if(n){
			a2[i]++;
			n--;
		}
	}
	ans+=a1[4]*a2[4];
	for(int i=0;i<4;i++)
	ans+=a1[i]*a2[3-i];
	cout<<ans<<endl;
	return 0;
}
