#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
int main (){
	ll tc,n,x,y,a[100001],b[100001],sum;
	cin>>tc;
	while(tc--){
		cin>>n>>x>>y;
		sum=0;
		for(int i=0;i<n;i++) cin>>a[i]>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		for(int i=0;i<n;i++){
			if(b[i]>a[i]) sum+=(b[i]-a[i])*x;
			else sum+=(a[i]-b[i])*y;
		}
		cout<<sum<<endl;
	}
	return 0;
}
