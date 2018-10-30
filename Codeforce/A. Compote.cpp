#include <iostream>
using namespace std;
int main (){
	int a,b,c,ans;
	cin>>a>>b>>c;
	ans=min(a,b/2);
	ans=min(ans,c/4);
	cout<<ans*7<<endl;
	return 0;
}
