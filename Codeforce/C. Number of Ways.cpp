#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
ll onetoi[500005]={0},ntoi[500005]={0},arr[500005]={0},sum=0,sumtemp=0,n,ans=0,cur=0;
int main (){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	if((n<3)||(sum%3!=0)){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n-2;i++){
		sumtemp+=arr[i];
		if(sumtemp==sum/3) onetoi[i]=1;
		else onetoi[i]=0;
	}
	sumtemp=0;
	for(int i=n;i>=3;i--){
		sumtemp+=arr[i];
		if(sumtemp==sum/3) ntoi[i]=ntoi[i+1]+1;
		else ntoi[i]=ntoi[i+1];
		//cout<<ntoi[i]<<" "<<i<<" "<<endl;
	}
	//for(int i=3;i<=n;i++) cout<<ntoi[i]<<endl;
	for(int i=1;i<=n-2;i++){
		ans+=onetoi[i]*ntoi[i+2];
	}
	cout<<ans<<endl;
}
