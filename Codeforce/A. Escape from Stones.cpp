#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int main (){
	ios::sync_with_stdio(false);
	vector<int> ans;
	string s;
	int pos=0;
	cin>>s;
	ans.push_back(1);
	for(int i=0;i<s.size()-1;i++){
		//cout<<s[i]<<endl;
		if(s[i]=='l') ans.insert(ans.begin()+pos,i+2);
		else ans.insert(ans.begin()+(++pos),i+2);
	}
	for(int i=0;i<ans.size();i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
