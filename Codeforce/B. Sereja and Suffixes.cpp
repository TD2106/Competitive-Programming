#include <iostream>
#include <map>
using namespace std;
int main (){
	map<int,bool> marking;
	int n,m,arr[100010]={0},ans[100010]={0},l;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=n;i>=1;i--){
		if(!marking[arr[i]]){
			marking[arr[i]]=1;
			ans[i]=ans[i+1]+1;
		}
		else ans[i]=ans[i+1];
	}
	while(m--){
		cin>>l;
		cout<<ans[l]<<endl;
	}
	return 0;
}
