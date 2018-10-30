#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main (){
	int n,q,num;
	vector<int> arr;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>num;
		arr.push_back(num);
	}
	sort(arr.begin(),arr.end());
	while(q--){
		cin>>num;
		vector<int>::iterator itr;
		itr=lower_bound(arr.begin(),arr.end(),num);
		if(*itr==num) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
