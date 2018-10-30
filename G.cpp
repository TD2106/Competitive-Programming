#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
typedef vector<int> lnum;
const int base=1000*1000*1000;
void input(string s,lnum& a){
	for(int i=(int)s.size();i>0;i-=9){
		if(i<9){
			stringstream ss;
			ss.str(s.substr(0,i));
			int temp;
			ss>>temp;
			a.push_back(temp);
		}
		else{
			stringstream ss;
			ss.str(s.substr(i-9,9));
			int temp;
			ss>>temp;
			a.push_back(temp);
		}
	}
	while(a.size()>1&&a.back()==0)
	a.pop_back();
}
bool compare(lnum a){
	if(a.size()==1&&a[0]==1)
	return true;
	else return false;
}
void divide(lnum &a,int b){
	long long carry = 0;
	for(int i=(int)a.size()-1;i>=0;--i){
		long long cur = a[i]+carry*base;
		a[i]=(int)(cur/b);
		carry=(int)(cur%b);
	}
	while(a.size()>1&&a.back()==0)
	a.pop_back();
}
int main (){
	lnum a;
	string s;
	cin>>s;
	input(s,a);
	int res=0;
	if(s=="0"){
		cout<<0<<endl;
		return 0;
	}
	if(compare(a)){
		cout<<1<<endl;
		return 0;
	}
	
	while(!compare(a)){
		divide(a,++res);
	}
	cout<<res<<endl;
}
