#include <iostream>
#include <bitset>
#include <map>
using namespace std;
bitset<1000001> mark;
map<int,int> primefactor;
void sieve(){
	for(int i=2;i<=1000000;i++){
		if(!mark[i]){
			primefactor[i]++;
			for(int j=i*2;j<=1000000;j+=i){
				if(!mark[j])
				primefactor[i]++;
				mark[j]=1;
			}
		}
	}
}
int main (){
	int tc,x;
	cin>>tc;
	sieve();
	while(tc--){
		cin>>x;
		cout<<primefactor[x]<<endl;
	}
}
