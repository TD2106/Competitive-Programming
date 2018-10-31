#include <iostream>
#include <cmath>
#include <map>
using namespace std;
map<int,int> marking;
int power(int n){
	if(n==0) return 1;
	if(marking[n]) return marking[n];
	else{
		if(n%2) return marking[n]=(8*(power(n/2)%10*power(n/2)%10))%10;
		else return marking[n]=(power(n/2)%10*power(n/2))%10;
	}
}
int main (){
	int n;
	cin>>n;
	cout<<power(n)<<endl;
}
