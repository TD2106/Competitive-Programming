#include <iostream>
using namespace std;
int main (){
	int n,arr[105]={0},a,b,ans=0;
	cin>>n;
	for(int i=1;i<n;i++) cin>>arr[i];
	cin>>a>>b;
	for(int i=a;i<b;i++) ans+=arr[i];
	cout<<ans<<endl;
}
