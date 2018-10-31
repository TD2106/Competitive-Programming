#include <iostream>
using namespace std;
int main (){
	int n,t,c,ans=0,arr[200010]={0},i,j=0;
	cin>>n>>t>>c;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(i=1;i<=n;i++){
		if(arr[i]<=t) j++;
		else {
			if(j>=c) ans+=(j-c+1);
			j=0;
		}
	}
	if(j>=c) ans+=(j-c+1);
	cout<<ans<<endl;
}
