#include <iostream>
using namespace std;
int main (){
	string s;
	int tc,i,j;
	cin>>tc;
	while(tc--){
		string ans;
		cin>>s;
		for(i=0;i<s.size();i++){
			ans+=s[i];
			for(j=i+1;j<s.size();j++)
			if(s[j]!=s[i]) break;
			i=--j;
		}
		cout<<ans<<endl;
	}
}
