#include <iostream>
#include <algorithm>
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
//vector<string> data;
int main (){
	string s;
	s="00";
	//data.push_back(s);
	for(int i=0;i<48;i++){
		if(check(s+"1")) s+="1";
		else if(check(s+"0")) s+="0";
		else{
			string temp=s;
			temp.insert(temp.begin(),'1');
			if(check1(temp)) s=temp;
			else{
				temp.erase(temp.begin());
				temp.insert(temp.begin(),'0');
				if(check1(temp)) s=temp;
			}
		}
	}
	//cout<<s.size()<<endl;
	cout<<s<<endl;
}
