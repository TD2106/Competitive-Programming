#include <iostream>
#include <string>
using namespace std;
int main (){
	string arrofstr[26]={"@","8","(","|)","3","#","6","[-]","|","_|","|<","1","[]\\/[]","[]\\[]","0","|D","(,)","|Z","$","']['","|_|","\\/","\\/\\/","}{","`/","2"};
	string s,result;
	getline(cin,s);
	for(int i=0;i<s.size()&&s[i]!='\n';i++){
		if(s[i]>='a'&&s[i]<='z')
		result+=arrofstr[s[i]-'a'];
		else if(s[i]>='A'&&s[i]<='Z')
		result+=arrofstr[s[i]-'A'];
		else result+=s[i];
	}
	cout<<result;
	return 0;
}
