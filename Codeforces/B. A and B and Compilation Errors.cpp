#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
void process(vector<int> &a,vector<int> &b){
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]){
			cout<<b[i]<<endl;
			return ;
		}
	}
	cout<<b[a.size()]<<endl;
}
int main (){
	ios::sync_with_stdio(false);
	vector<int> pre,aft;
	int n,temp,check=1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		pre.push_back(temp);
	}
	for(int i=0;i<n-1;i++){
		cin>>temp;
		aft.push_back(temp);
	}
	sort(pre.begin(),pre.end());
	sort(aft.begin(),aft.end());
	process(aft,pre);
	pre.clear();
	for(int i=0;i<n-2;i++){
		cin>>temp;
		pre.push_back(temp);
	}
	sort(pre.begin(),pre.end());
	check=1;
	process(pre,aft);
}
