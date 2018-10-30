#include <iostream>
#include <algorithm>
using namespace std;
int main (){
	int n,a,b,i,j,ans;
	string s;
	cin>>n>>a>>b>>s;
	if(a>b) swap(a,b);
	a--,b--;
	if(s[a]==s[b]){
		cout<<0<<endl;
		return 0;
	}
	ans=b-a;
	i=j=-1;
	for(int k=0;k<n;k++){
		if(s[k]=='1') i=k;
		else j=k;
		if(i!=-1&&j!=-1) ans=min(ans,abs(i-j));
	}
	cout<<ans<<endl;
	return 0;
}
