#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main (){
	ll n,ans,chia,i;
	while(cin>>n){
		//cout<<n<<endl;
		if(n<5) cout<<0<<endl;
		else if(n>=5&&n<=9)
		cout<<1<<endl;
		else{
			ll arr[12]={0};
			ans=0;
			i=1;
			chia=10;
			while(chia<=n){
				arr[i]=(n/chia);
				i++;
				chia*=10;
			}
			for(int i=1;i<=10;i++){
				for(int j=i+1;j<=10;j++)
				arr[i]-=arr[j];
			}
			for(int i=1;i<=10;i++){
				ans+=i*arr[i];
			}
			if((n%10)>=5) ans+=(arr[1]+1);
			else ans+=arr[1];
			cout<<ans<<endl;
		}
	}
}
