#include <iostream>
#include <cmath>
using namespace std;
int main (){
	int n,a,b,st;
	cin>>n;
	st=sqrt(n);
	for(int i=st;i>=1;i--){
		if(n%i==0){
			cout<<i<<" "<<n/i<<endl;
			break;
		}
	}
	return 0;
}
