#include <iostream>
#include <map>
using namespace std;
int main (){
	map<string,int> data;
	string s[200005];
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=n-1;i>=0;i--){
		if(data[s[i]]==0){
			data[s[i]]++;
			cout<<s[i]<<endl;
		}
	}
	return 0;
}
