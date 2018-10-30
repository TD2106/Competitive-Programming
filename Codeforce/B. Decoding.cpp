#include <iostream>
using namespace std;
int main (){
	string s,ans;
	char temp[2005]={0};
	int n,l,r;
	cin>>n>>s;
	if(n%2){
		l=r=n/2;
		for(int i=0;i<s.size();i++){
			if(i==0) temp[l]=s[i],l--,r++;
			else if(i%2) temp[l]=s[i],l--;
			else temp[r]=s[i],r++;
		}
	}
	else{
		l=n/2-1;
		r=n/2;
		for(int i=0;i<s.size();i++){
			if(i%2==0) temp[l]=s[i],l--;
			else temp[r]=s[i],r++;
		}
	}
	ans=string(temp);
	cout<<ans<<endl;
}
