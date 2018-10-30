#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
bool mycmp(pair<int,string> a,pair<int,string> b){
	return (a.first>b.first||a.first==b.first&&a.second<b.second);
}
int main (){
	int n,t,quo;
	string s;
	cin>>n>>t;
	pair<int,string> arr[1000];
	for(int i=0;i<n;i++){
		cin>>s>>quo;
		arr[i]=make_pair(quo,s);
	}
	sort(arr,arr+n,mycmp);
	for(int i=0;i<t;i++){
		cout<<arr[i].second<<endl;
	}
	return 0;
}
