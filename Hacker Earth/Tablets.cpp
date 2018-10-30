#include <iostream>
using namespace std;
int main (){
	long long n,arr[100010]={100001,0},tablet[100010]={0},sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]<=arr[i-1])
		tablet[i]=1;
		else tablet[i]=tablet[i-1]+1;
	}
	for(int i=n-1;i>0;i--){
		if(arr[i]>arr[i+1]&&tablet[i]<=tablet[i+1])
		tablet[i]=tablet[i+1]+1;
	}
	for(int i=1;i<=n;i++) sum+=tablet[i];
	cout<<sum;
	return 0;
}
