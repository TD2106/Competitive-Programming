#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,k,temp,lo,hi,mid;
vector<int> arr;
bool check(){
	int index=0;
	vector<int>::iterator itr;
	temp=k;
	while(temp--){
		itr=upper_bound(arr.begin(),arr.end(),arr[index]+2*mid);
		itr--;
		if(itr==arr.end()-1) return 1;
		index=itr-arr.begin()+1;
	}
	return 0;
}
int main (){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>temp;
		arr.push_back(temp);
	}
	sort(arr.begin(),arr.end());
	lo=0,hi=10000000;
	while(lo<hi){
		mid=(lo+hi)/2;
		if(check()) hi=mid;
		else lo=mid+1;
	}
	cout<<lo<<endl;
}
