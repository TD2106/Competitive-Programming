#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main (){
	long long tc,n,q,arr[1010],total;
	cin>>tc;
	while(tc--){
		total=0;
		memset(arr,0,sizeof(arr));
		cin>>n>>q;
		for(int i=1;i<=n;i++) cin>>arr[i];
		if(n==1) cout<<0<<endl;
		else{
			sort(arr+1,arr+1+n);
			for(int i=1;i<n;i++)
			total+=q*(arr[i+1]-arr[i]);
			cout<<total<<endl;
		}
	}
	return 0;
}
