#include <iostream>
using namespace std;
int main (){
	string s;
	int sumOfGene[4]={0},re=0,m,plus[4],n;
	cin>>n>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='A') sumOfGene[0]++;
		else if(s[i]=='C') sumOfGene[1]++;
		else if(s[i]=='G') sumOfGene[2]++;
		else if(s[i]=='T') sumOfGene[3]++;
		else re++;
	}
	m=max(sumOfGene[0],sumOfGene[1]);
	m=max(m,sumOfGene[2]);
	m=max(m,sumOfGene[3]);
	for(int i=0;i<4;i++){
		plus[i]=m-sumOfGene[i];
		re-=m-sumOfGene[i];
	}
	if(re<0||(re%4)!=0) cout<<"===\n";
	else{
		for(int i=0;i<4;i++) plus[i]+=re/4;
		for(int i=0;i<s.size();i++){
			if(plus[0]&&s[i]=='?') s[i]='A',plus[0]--;
			else if(plus[1]&&s[i]=='?') s[i]='C',plus[1]--;
			else if(plus[2]&&s[i]=='?') s[i]='G',plus[2]--;
			else if(plus[3]&&s[i]=='?') s[i]='T',plus[3]--;
		}
		cout<<s<<endl;
	}
	return 0;
}
