#include <iostream>
#include <sstream>
#include <map>
using namespace std;
string itos(int a){
	stringstream ss;
	ss<<a;
	return ss.str();
}
int main (){
	int n;
	string s;
	map<string,int> data;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		if(data[s]==0){
			cout<<"OK\n";
			data[s]++;
		}
		else{
			cout<<s+itos(data[s])<<endl;
			data[s]++;
		}
	}
	return 0;
}
