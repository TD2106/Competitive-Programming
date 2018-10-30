#include <iostream>
using namespace std;
int main (){
	int arr[500]={0},k,total=0,n;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=1;i<n;i++){
		if(arr[i]+arr[i-1]>=k) continue;
		else{
			total+=k-arr[i-1]-arr[i];
			arr[i]=k-arr[i-1];
		}
	}
	cout<<total<<endl;
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	return 0;
}
