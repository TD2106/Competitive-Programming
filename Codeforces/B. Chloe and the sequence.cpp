#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int main (){
	ll n,k,len,sto[51]={0};
	cin>>n>>k;
	len=pow(2,n)-1;
	for(int i=1;i<=n;i++) sto[i]=pow(2,i)-1;
	if(k%2) cout<<1<<endl;
	else{
		while(k<sto[n]){
			if(k==sto[n]/2+1){
				cout<<n;
				return 0;
			}
			else{
				if(k>sto[n]/2+1) k-=sto[n]/2+1;
				n--;
			}
		}
	}
	return 0;
}
