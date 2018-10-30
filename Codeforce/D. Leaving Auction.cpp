#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
vector<int> pa[200010];
map<int,int> data;
map<int,int>::iterator itr;
int n,q,k,bid[200010]={0},todel[200010]={0},a,b,t;
int main (){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		bid[a]=b;
		pa[a].push_back(b);
	}
	for(int i=1;i<=n;i++)
	if(bid[i]) data[bid[i]]=i;
	cin>>q;
	while(q--){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>todel[i];
			if(bid[todel[i]]) data.erase(bid[todel[i]]);
		}
		if(data.size()==0) cout<<"0 0\n";
		else if(data.size()==1) cout<<data.begin()->second<<" "<<pa[data.begin()->second][0]<<endl;
		else{
			itr=data.end();
			itr--;
			t=itr->second;
			itr--;
			cout<<t<<" "<<*upper_bound(pa[t].begin(),pa[t].end(),itr->first)<<endl;
		}
		for(int i=1;i<=k;i++) 
		if(bid[todel[i]]) data[bid[todel[i]]]=todel[i];
	}
	return 0;
}
