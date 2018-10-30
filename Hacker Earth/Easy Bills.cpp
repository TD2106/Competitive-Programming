#include <iostream>
#include <cstring>
using namespace std;
int main (){
	int n,b,l,r,temp,sum[100010]={0};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>temp;
		sum[i]=sum[i-1]+temp;
	}
	cin>>b;
	while(b--){
		cin>>l>>r;
		cout<<sum[r]-sum[l]<<endl;
	}
	return 0;
}
