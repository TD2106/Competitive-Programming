#include <iostream>
#include <map>
#include <set>
using namespace std;
int main (){
	int n,ans,st,en=0,total=1000000;
	string s;
	map<char,int> data;
	set<char> sz;
	cin>>n>>s;
	for(int i=0;i<n;i++) sz.insert(s[i]);
	//cout<<sz.size()<<endl;
	for(int i=0;i<n;i++){
        while(data.size()<sz.size()&&en<n) data[s[en++]]++;
        if(data.size()==sz.size()) total=min(total,en-i);
        data[s[i]]--;
        if(data[s[i]]==0) data.erase(s[i]);
	}
	cout<<total<<endl;
	return 0;
}
