#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main (){
	int n,arr[1010]={0},res[1010]={0},ans=0,index=1,temp;
	cin>>n;
	temp=n;
	for(int i=1;i<=n;i++)
	cin>>arr[i];
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++){
		if(i%2) res[index++]=arr[i];
		else res[temp--]=arr[i];
	}
	for(int i=1;i<n;i++){
		ans=max(ans,abs(res[i+1]-res[i]));
	}
	ans=max(ans,abs(res[n]-res[1]));
	cout<<ans<<endl;
	return 0;
}
