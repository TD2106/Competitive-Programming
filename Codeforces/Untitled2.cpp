#include <iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
	if(a*b==0) return a+b;
	else return gcd(b,a%b);
}
int main (){
	cout<<gcd(-3,-1)<<endl;
}
