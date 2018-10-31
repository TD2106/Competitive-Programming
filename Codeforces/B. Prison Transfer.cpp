#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;
typedef long long ll;
ll arr[200010]={0},t,c,n,start=1,ans=0;
bool flag=1;
int main (){
	cin>>n>>t>>c;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]<=t&&i-start==c-1&&flag) flag=0;
		if(arr[i]>t&&i-start<c-1&&flag) start=i+1;
	}
	if(flag){
		cout<<0<<endl;
		return 0;
	}
	for(int i=start;i<=n-c+1;i++){
		if(arr[i+c-1]>t) i=i+c-1;
		else ans++;
	}
	cout<<ans<<endl;
	return 0;
}
