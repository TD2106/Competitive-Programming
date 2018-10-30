#include <iostream>
#include <cstring>
using namespace std;
int upper[1000001],lower[1000001];
int main (){
	int tc,l,ans;
	cin>>tc;
	while(tc--){
		cin>>l;
		memset(upper,0,sizeof(upper));
		memset(lower,0,sizeof(lower));
		ans=0;
		for(int i=1;i<=l-1;i++){
			cin>>upper[i];
			ans=max(i+upper[i],ans);
		}
		for(int i=1;i<=l-1;i++){
			cin>>lower[i];
			ans=max(i+lower[i],ans);
		}
		ans=max(ans,l);
		cout<<ans<<endl;
	}
	return 0;
}
