#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main (){
	ll ans=0,n,value,x,y[1001]={0},temp,mod=100000,sz,num;
	bool check[100000]={0},flag=1,fill;
	vector<ll> data;
	cin>>x>>value;
	cin>>n;
	data.push_back(x);
	for(int i=0;i<n;i++) cin>>y[i];
	if(x==value){
		cout<<0<<endl;
		return 0;
	}
	while(1){
		fill=1;
		ans++;
		sz=data.size();
		//cout<<sz<<endl;
		while(sz--){
			num=*data.begin();
			//cout<<num<<endl;
			data.erase(data.begin());
			for(int i=0;i<n;i++){
				temp=(num*y[i])%mod;
				if(!check[temp]){
					check[temp]=1;
					fill=0;
					data.push_back(temp);
				}
				if(temp==value){
					cout<<ans<<endl;
					return 0;
				}
			}
		}
		if(fill){
			//cout<<1<<endl;
			//cout<<temp<<" "<<num<<endl;
			break;
		}
	}
	if(flag) cout<<-1<<endl;
	return 0;
}
