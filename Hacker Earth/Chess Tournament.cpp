#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
bool marking[1050][1050]={0};
int main (){
	vector<int> pre,ans;
	int n,temp;
	cin>>n;
	temp=(int)pow(2,n);
	for(int i=1;i<=temp;i++)
	pre.push_back(i);
	for(int i=2;i<=temp;i++){
		for(int j=1;j<i;j++){
			cin>>marking[i][j];
		}
	}
	while(ans.size()!=1){
		ans.clear();
		for(int i=0;i<pre.size()-1;i+=2){
			if(marking[pre[i+1]][pre[i]])
			ans.push_back(pre[i+1]);
			else
			ans.push_back(pre[i]);
		}
		pre=ans;
	}
	cout<<ans[0]<<endl;
	return 0;
}
