#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main (){
	int tc,arr[100000],n;
	cin>>tc;
	while(tc--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		for(int i=n-1;i>=0;i--)
		cout<<arr[i]<<" ";
		cout<<endl;
	}
	return 0;
}
