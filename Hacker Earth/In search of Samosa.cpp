#include <iostream>
#include <algorithm>
using namespace std;
int main (){
	int n,k,ans=0,arr[1000]={0},index=0;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	while(k>=arr[index]){
		k-=arr[index];
		index++;
	}
	cout<<index<<endl;
	return 0;
}
