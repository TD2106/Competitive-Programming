#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;
int main (){
	int n,temp;
	bitset<1000005> marking;
	cin>>n;
	for(int i=2;i*i<=n;i++){
		//cout<<i<<endl;
		if(marking[i]==0){
			for(int j=i*i;j<=n;j+=i){
				marking[j]=1;
				//cout<<j<<endl;
			}	
		}
	}
	for(int i=2;i<=n;i++){
		if(!marking[i])
		cout<<i<<" ";
	}
	return 0;
}
