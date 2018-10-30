#include <iostream>
#include <cstring>
using namespace std;
int main (){
	int ch[26],tc;
	bool flag;
	string s;
	cin>>tc;
	while(tc--){
		cin>>s;
		flag=1;
		memset(ch,0,sizeof(ch));
		for(int i=0;i<s.size();i++){
			ch[s[i]-'a']++;
		}
		for(int i=0;i<26;i++){
			if(ch[i]%2){
				cout<<"-1\n";
				flag=0;
				break;	
			}
		}
		if(flag) cout<<"1\n";
	}
	return 0;
}
