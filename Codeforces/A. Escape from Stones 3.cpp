#include <iostream>
#include <vector>
using namespace std;
int main (){
	ios::sync_with_stdio(false);
	char s;
	vector<int> r,l;
	int i=0;
	while(cin>>s){
		if(s=='r') r.push_back(++i);
		else l.push_back(++i);
	}
	for(int i=0;i<r.size();i++){
		cout<<r[i]<<endl;
	}
	for(int i=l.size()-1;i>=0;i--){
		cout<<l[i]<<endl;
	}
	return 0;
}
