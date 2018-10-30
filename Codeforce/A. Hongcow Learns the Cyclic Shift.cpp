#include <iostream>
#include <set>
using namespace std;
int main (){
	string s;
	cin>>s;
	set<string> str;
	str.insert(s);
	int n=s.size();
	while(n--){
		s.insert(s.begin(),s[s.size()-1]);
		s.erase(s.end()-1);
		str.insert(s);
	}
	cout<<str.size();
	return 0;
}
