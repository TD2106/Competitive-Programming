#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool check (string s){
	string a,b,c;
	for(int j=0;j<s.size()/3;j++){
		int index=s.size()-1;
		for(int i=0;i<3;i++){
			if(i==0){
				a=s.substr(index-j,j+1);
			}
			if(i==1){
				b=s.substr(index-j,j+1);
			}
			if(i==2){
				c=s.substr(index-j,j+1);
			}
			index=index-(j+1);
		}
		if(a==b&&a==c)
		return 0;
	}
	return 1;
}
bool check1 (string s){
	string a,b,c;
	for(int j=0;j<s.size()/3;j++){
		int index=0;
		for(int i=0;i<3;i++){
			if(i==0){
				a=s.substr(index,j+1);
			}
			if(i==1){
				b=s.substr(index,j+1);
			}
			if(i==2){
				c=s.substr(index,j+1);
			}
			index+=j+1;
		}
		if(a==b&&a==c)
		return 0;
	}
	return 1;
}
vector<string> data;
int main (){
	string s;
	s="";
	data.push_back(s);
	while(!data.empty()&&data[0].size()!=50){
		s=data[0];
		if(check(s+"1")) data.push_back(s+"1");
		if(check(s+"0")) data.push_back(s+"0");
		if(check1("0"+s)){
			string temp=s;
			temp.insert(temp.begin(),'0');
			data.push_back(temp);
		}
		if(check1("1"+s)){
			string temp=s;
			temp.insert(temp.begin(),'1');
			data.push_back(temp);
		}
		data.erase(data.begin());
	}
	//cout<<s.size()<<endl;
	cout<<data[0]<<endl;
}
