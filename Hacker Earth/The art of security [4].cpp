#include <iostream>
#include <vector>
using namespace std;
vector<int> bi;
int n,power[10]={0},sum=0,gate1,way=0,one;
int fac(int n){
	if(n==1||n==0) return 1;
	else return n*fac(n-1);
}
void recursion(int ti){
	for(int i=0;i<2;i++){
		bi.push_back(i);
		if(ti==n-1){
			//cout<<"YES\n";
			gate1=one=0;
			for(int j=0;j<n;j++){
				if(bi[j]) gate1+=power[j],one++;
				//cout<<"YES\n";
				//cout<<j<<endl;
			}
			//cout<<"YES"<<endl;
			if(gate1<=sum-gate1){
				//cout<<"YES\n";
				way+=fac(n);
				//cout<<way<<endl;
			}
		}
		else recursion(ti+1);
		bi.pop_back();
	}
}
int main (){
	cin>>n;
	for(int i=0;i<n;i++) cin>>power[i],sum+=power[i];
	//cout<<sum<<endl;
	//cout<<fac(8)<<endl;
	recursion(0);
	cout<<way<<" "<<sum<<endl;
	if(way<sum) cout<<"Got no way out!\n";
	else cout<<"We will win!\n";
	return 0;
}
