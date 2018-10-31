#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <list>
using namespace std;
int main (){
	//ios::sync_with_stdio(false);
	list<int>::iterator itr;
	string s;
	cin>>s;
	list<int> ans;
	ans.push_back(1);
	itr=ans.begin();
	for(int i=0;i<s.size()-1;i++){
		//cout<<i<<endl;
		//cout<<*itr<<endl;
		//cout<<s[i]<<endl;
		if(s[i]=='l'){
			ans.insert(itr,i+2);
			itr--;
		}
		else{
			itr++;
			ans.insert(itr,i+2);
			itr--;
		}
	}
	for(itr=ans.begin();itr!=ans.end();itr++){
		printf("%d\n",*itr);
	}
	return 0;
}
