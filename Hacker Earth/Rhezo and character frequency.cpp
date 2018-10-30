#include <iostream>
using namespace std;
int main (){
	string s;
	char ch;
	int sum[1005]={0},p,z=0,flag;
	cin>>s>>ch>>p;
	for(int i=1;i<=s.size();i++){
		sum[i]=sum[i-1];
		if(s[i-1]==ch) sum[i]++;
	}
	for(int i=s.size();i>=p;i--)
	z=max(z,sum[i]-sum[i-p]);
	if(z==p) cout<<"-1";
	else{
		for(int i=s.size();i>=p;i--){
			flag=0;
			if(sum[i]-sum[i-p]==z){
				for(int j=i;j>i-p;j--)
				if(s[j-1]!=ch){
					cout<<j-1;
					flag=1;
					break;
				}
			}
			if(flag) break;
		}
	}
	return 0;
}
