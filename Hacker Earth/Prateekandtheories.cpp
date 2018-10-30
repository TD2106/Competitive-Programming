#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
int main (){
	ll tc,n,t1,t2,sum,ans;
	map<ll,ll> arr;
	cin>>tc;
	while(tc--){
		sum=ans=0;
		arr.clear();
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>t1>>t2;
			arr[t1]++;
			arr[t2]--;
		}
		for(map<ll,ll>::iterator itr=arr.begin();itr!=arr.end();itr++){
			sum+=itr->second;
			ans=max(ans,sum);
		}
		cout<<ans<<endl;
	}
	return 0;
}
