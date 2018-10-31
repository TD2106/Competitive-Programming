#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define mod 1000000007
using namespace std;
typedef long long int ll;
ll Ti=1,t=0;
string s;
map<char,ll> mp;
map<ll,ll> cnt;
int main(){
	ios_base::sync_with_stdio(0);
	for(int i=0;i<=63;i++){
        for(int j=0;j<=63;j++){
            int temp=i&j;
            cnt[temp]++;
        }
	}
	for(char c='0';c<='9';c++) mp[c]=t++;
	for(char c='A';c<='Z';c++) mp[c]=t++;
	for(char c='a';c<='z';c++) mp[c]=t++;
	mp['-']=62,mp['_']=63;
	cin>>s;
	for(int i=0;i<s.size();i++){
        Ti*=cnt[mp[s[i]]];
        Ti%=mod;
	}
	cout<<Ti<<endl;
	return 0;
}
