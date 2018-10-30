#include <iostream>
#include <algorithm>
using namespace std;
int main (){
	int f[50]={0},n,m,res=1000;
	cin>>n>>m;
	for(int i=0;i<m;i++) cin>>f[i];
	sort(f,f+m);
	for(int i=0;i<=m-n;i++){
		res=min(f[i+n-1]-f[i],res);
	}
	cout<<res<<endl;
	return 0;
}
