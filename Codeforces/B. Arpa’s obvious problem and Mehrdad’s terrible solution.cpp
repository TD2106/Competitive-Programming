#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main (){
	vector<ll> arr;
	vector<ll>::iterator low,up;
	ll n,temp,x,ans=0;
	cin>>n>>x;
	for(int i=0;i<n;i++) cin>>temp,arr.push_back(temp);
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++){
		temp=x^arr[i];
		low=lower_bound(arr.begin()+i+1,arr.end(),temp);
		up=upper_bound(arr.begin()+i+1,arr.end(),temp);
		ans+=up-low;
	}
	cout<<ans<<endl;
}
