#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main (){
	ios::sync_with_stdio(false);
	vector< pair<int,int> > pos;
	pair<int,int> temp;
	int n,d,count=0,index=0,x=0;
	string s="#",str;
	cin>>n>>d;
	cin>>str;
	s+=str+"#";
	for(int i=1;i<=n;i++){
		if(s[i]=='.'&&s[i-1]=='#')
		temp.first=i;
		if(s[i]=='.'&&s[i+1]=='#'){
			temp.second=i;
			pos.push_back(temp);
		}
	}
	if(pos.size()==1){
		cout<<1<<endl;
		return 0;
	}
	while(index<=pos.size()-1){
		count++;
		while(pos[index].second+d>=pos[x].first&&index<pos.size()&&x<pos.size())
		x++;
		index=--x;
		while(pos[index].second+d>=pos[x].first&&index<pos.size()&&x<pos.size())
		x++;
		index=x;
		//cout<<index<<endl;
	}
	cout<<count<<endl;
}
