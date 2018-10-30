#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main (){
	int tc,n,m,boy[10000],girl[10000];
	cin>>tc;
	while(tc--){
		cin>>m>>n;
		memset(boy,0,sizeof(boy));
		memset(girl,0,sizeof(girl));
		for(int i=0;i<m;i++) cin>>boy[i];
		for(int i=0;i<n;i++) cin>>girl[i];
		sort(boy,boy+m);
		sort(girl,girl+n);
		bool flag=1;
		for(int i=0;i<m;i++){
			if(boy[i]<girl[i]){
				flag=0;
				break;
			}
		}
		if(flag) cout<<"YES\n";
		else if(flag==0||n<m) cout<<"NO\n";
	}
	return 0;
}
