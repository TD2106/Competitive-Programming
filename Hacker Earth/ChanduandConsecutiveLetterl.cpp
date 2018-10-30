#include <iostream>
using namespace std;
int main (){
	int tc,i,j;
	string s,ans;
	cin>>tc;
	while(tc--){
		cin>>s;
		ans.clear();
		for(i=0;i<s.size();i++){
			ans+=s[i];
			for(j=i+1;j<s.size();j++){
				if(s[j]!=s[i]) break;
			}
			i=--j;
		}
		cout<<ans<<endl;
	}	
	return 0;
}

