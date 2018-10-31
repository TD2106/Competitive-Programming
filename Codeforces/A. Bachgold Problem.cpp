#include <iostream>
using namespace std;
int main (){
	int n;
	cin>>n;
	if(n%2){
		n-=3;
		cout<<n/2+1<<endl;
		for(int i=0;i<n/2;i++) cout<<2<<" ";
		cout<<3<<endl;
	}
	else{
		cout<<n/2<<endl;
		for(int i=0;i<n/2;i++) cout<<2<<" ";
	}
	return 0;
}
