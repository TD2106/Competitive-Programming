#include <iostream>
using namespace std;
int main (){
	long long n,temp,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>temp;
		cnt+=temp;
	}
	if(cnt/2==n-1)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}
