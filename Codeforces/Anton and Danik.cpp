#include <iostream>
using namespace std;
int main (){
	int n,s1=0,s2=0;
	cin>>n;
	char t;
	while(n--){
		cin>>t;
		if(t=='A')
		s1++;
		else
		s2++;
	}
	if(s1>s2){
		cout<<"Anton";
	}
	else if(s2>s1) cout<<"Danik";
	else cout<<"Friendship";
	return 0;
}
