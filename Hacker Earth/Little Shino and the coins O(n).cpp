#include <iostream>
#include <map>
using namespace std;
int main (){
	int k,ans=0,fik,lak=0,check=0;
	string s;
	cin>>k>>s;
	map<char,int> marking;
	for(int i=0;i<s.size();i++){
		marking[s[i]]++;
		check=0;
		for(int j=lak+1;j<s.size();j++){
			if((marking.size()==k)&&(check==0)){
				check=1;
				fik=j-1;
				//cout<<fik<<endl;
			}
			if((marking.size()==k)&&marking.count(s[j])==0){
				//cout<<"YES"<<" "<<lak<<endl;
				lak=j-1;
				break;
			}
			marking[s[j]]++;
			if(j==s.size()-1) lak=j;
		}
		//cout<<fik<<" "<<lak<<endl;
		cout<<i<<" "<<fik<<" "<<lak<<endl;
		if(marking.size()==k) ans+=lak-fik+1;
		if(marking.size()<k) break;
		marking[s[i]]--;
		if(marking[s[i]]==0) marking.erase(s[i]);
	}
	cout<<ans<<endl;
}
