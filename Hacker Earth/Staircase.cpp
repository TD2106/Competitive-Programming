#include <iostream>
using namespace std;
typedef long long ll;
int main (){
	ll n,ja[100010]={1},ji[100010]={1};
	ja[1]=ji[1]=1;
	ja[2]=ji[2]=2;
	ji[3]=3;
	ja[3]=4;
	cin>>n;
	for(int i=4;i<=n;i++){
		ja[i]=ja[i-1]+ja[i-2]+ja[i-3];
		ji[i]=ji[i-1]+ji[i-2];
	}
	if(n<0){
		cout<<"ERROR\n";
	}
	else{
		cout<<"Jack-"<<ja[n]<<endl;
		cout<<"Jill-"<<ji[n]<<endl;	
	}
	return 0;
}

