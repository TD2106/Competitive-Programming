#include <iostream>
#include <cmath>
using namespace std;
int main (){
	int n,m,tc;
	cin>>tc;
	while(tc--){
		cin>>n>>m;
		if(n==1||n==2)
		cout<<m<<endl;
		else{
			while(1){
				int temp=(int)ceilf(n*1.0/2);
				if(m%temp==0)
				break;
				else n--;
			}
			cout<<m/ceil(n*1.0/2)<<endl;
		}
	}
}
