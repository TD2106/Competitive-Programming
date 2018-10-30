#include <iostream>
using namespace std;
bool isPrime(int n){
	if(n==2||n==3)
	return 1;
	if(n%2==0||n%3==0)
	return 0;
	else{
		for(int i=5;i*i<=n;i+=6)
		if(n%i==0||n%(i+2)==0) return 0;
		return 1;
	}
}
int main (){
	int n;
	cin>>n;
	if(isPrime(n)){
		cout<<1<<endl;
	}
	else{
		if(n%2==0) cout<<2<<endl;
		else if(isPrime(n-2)) cout<<2<<endl;
		else cout<<3<<endl;
	}
}
