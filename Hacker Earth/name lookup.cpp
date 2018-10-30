#include <iostream>
#include <map>
using namespace std;
int main (){
	int n,q,roll;
	string name;
	map<int,string> data;
	cin>>n;
	while(n--){
		cin>>roll>>name;
		data[roll]=name;
	}
	cin>>q;
	while(q--){
		cin>>roll;
		cout<<data[roll]<<endl;
	}
	return 0;
}
