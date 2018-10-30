#include <iostream>
#include <map>
using namespace std;
bool isPalin(string s){
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])
		return 0;
	}
	return 1;
}
int main (){
	string s,sub;
	int tc,ans;
	cin>>tc;
	while(tc--){
		ans=0;
		map<string,int> data;
		cin>>s;
		for(int i=0;i<s.size();i++){
			sub.clear();
			sub+=s[i];
			data[sub]++;
			for(int j=i+1;j<s.size();j++){
				sub+=s[j];
				if(data.count(sub)==0){
					if(isPalin(sub))
					data[sub]++;
				}
				else data[sub]++;
			}
		}
		cout<<data.size()<<endl;
	}
}
