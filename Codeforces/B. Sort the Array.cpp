#include <iostream>
using namespace std;
int main (){
	int arr[100005]={0},n,sta=1,en=1,flag=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	arr[n+1]=2000000000;
	for(int i=1;i<=n;i++){
		if(arr[i]>arr[i+1]&&flag==0){
			//cout<<i<<endl;
			sta=i;
			flag=1;
		}
		if(arr[i]<arr[i+1]&&flag==1){
			//cout<<i<<endl;
			en=i;
			flag=2;
		}
	}
	//cout<<sta<<" "<<en<<endl;
	if(arr[sta-1]>arr[en]||arr[en+1]<arr[sta]){
	//	cout<<1<<endl;
		cout<<"no";
		return 0;
	}
	for(int i=1;i<=sta-2;i++){
		if(arr[i]>arr[i+1]){
		//	cout<<2<<endl;
			cout<<"no";
			return 0;
		}
	}
	for(int i=en+1;i<=n-1;i++){
		if(arr[i]>arr[i+1]){
		//	cout<<3<<endl;
			cout<<"no";
			return 0;
		}
	}
	cout<<"yes\n";
	cout<<sta<<" "<<en<<endl;
	return 0;
}
