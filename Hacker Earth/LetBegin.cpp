#include <iostream>
using namespace std;
int arr[1000001]={0},onedigitprime[4]={2,3,5,7},tc,x;
int main (){
	for(int i=2;i<=1000000;i++) arr[i]=1000000;
	arr[2]=arr[3]=1;
	arr[4]=2;
	arr[5]=1;
	arr[6]=2;
	arr[7]=1;
	arr[8]=2;
	for(int i=9;i<=1000000;i++){
		for(int j=0;j<4&&onedigitprime[j]<=i;j++)
		arr[i]=min(arr[i],1+arr[i-onedigitprime[j]]);
	}
	cin>>tc;
	while(tc--){
		cin>>x;
		if(arr[x]==0) cout<<"-1\n";
		else
		cout<<arr[x]<<endl;
	}
}
