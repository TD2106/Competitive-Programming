#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll cal(ll cnt){
	if(cnt<=1) return 0;
	else return cnt*(cnt-1)/2;
}
pair<ll,ll> arr[100001];
int main (){
	ll tc,cnt,ans;
	cin>>tc;
	while(tc--){
		string s;
		cin>>s;
		cnt=ans=0;
		memset(arr,0,sizeof(arr));
		for(int i=1;i<=s.size();i++){
			arr[i]=arr[i-1];
			if(s[i-1]=='a') arr[i].first++;
			if(s[i-1]=='b') arr[i].second++;
			if(s[i-1]=='c') arr[i].first--,arr[i].second--;
		}
		sort(arr,arr+s.size()+1);
		for(int i=0;i<s.size();i++){
			int j;
			for(j=i+1;j<s.size();j++){
				if(arr[j]!=arr[i]) break;
			}
			ans+=cal(j-i);
			i=--j;
		}
		cout<<ans<<endl;
	}	
}
