#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main (){
	int server[101]={0},t,k,d,ans=0,q,n,avai;
	for(int i=1;i<=100;i++) server[i]=1;
	cin>>n>>q;
	while(q--){
		cin>>t>>k>>d;
		ans=avai=0;
		for(int i=1;i<=n;i++) if(server[i]<=t) avai++;
		if(avai>=k){
			for(int i=1;i<=n&&k!=0;i++){
				if(server[i]<=t) server[i]=t+d,k--,ans+=i;;
			}
			cout<<ans<<endl;
		}
		else cout<<-1<<endl;
	}
	return 0;
}
