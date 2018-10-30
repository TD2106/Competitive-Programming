#include <iostream>
using namespace std;
int main (){
	string s;
	int sum[10010]={0};
	cin>>s;
	for(int i=0;i<s.size();i++){
		int temp=s[i]-'0';
		if(temp%2==0)
		sum[i+1]++;
		sum[i+1]+=sum[i];
	}
	for(int i=0;i<s.size();i++)
	cout<<sum[s.size()]-sum[i]<<" ";
	return 0;
}
