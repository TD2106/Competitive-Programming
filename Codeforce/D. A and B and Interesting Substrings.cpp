#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
ll point[26],sum[100010]={0},ans=0;
map<ll,ll> pos[26];
int main (){
	for(int i=0;i<26;i++) cin>>point[i];
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		sum[i+1]=point[s[i]-'a']+sum[i];
		ans+=pos[s[i]-'a'][sum[i]];
		pos[s[i]-'a'][sum[i+1]]++;
		//cout<<sum<<endl;
	}
	cout<<ans<<endl;
}
