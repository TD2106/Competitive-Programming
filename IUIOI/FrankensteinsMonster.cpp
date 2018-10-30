#include <iostream>
using namespace std;
int main (){
	string s,ans,word;
	cin>>s;
	ans="";
	for(int i=0;i<s.size();i++){
		if (s[i]!='.'){
			word+=s[i];
		}
		else{
			if(word=="Frankenstein")
			ans+=word+"'s.monster";
			else ans+=word;
			word.clear();
			ans+=s[i];
		}
		if(i==s.size()-1&&s[i]!='.'){
			if(word=="Frankenstein")
			ans+=word+"'s.monster";
			else ans+=word;
			word.clear();
		}
		//ans+=s[i];
		//if(ans.substr(i,12)=="Frankenstein")
		//ans+="'s.monster";
	}
	cout<<ans<<endl;
}
